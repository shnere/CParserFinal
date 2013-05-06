#include <stdio.h>
#include "Parser.hh"

Parser::Parser(Lexer ** l)
{
  this->top = NULL;
  this->used = 0;
  this->lex = *l;
  this->move();  
}

Parser::~Parser()
{
}

void Parser::move() {
  this->look = this->lex->scan();
}

void Parser::program() { // Program -> Block
  Stmt * s = block();
  int begin = s->newlabel();
  int after = s->newlabel();
  s->emitlabel(begin);
  s->gen(begin, after);
  s->emitlabel(after);
}

/* GRAMMAR METHODS */
Stmt * Parser::block() { // Block -> { DD SS }
  match('{');
  Env * savedEnv = this->top;
  this->top = new Env(this->top);
  decls();
  Stmt * s = stmts();
  match('}');
  this->top = savedEnv;
  return s;
}

void Parser::decls() { // D -> type ID
  while ( this->look->getTag() == Token::BASIC ) {
    Type * p = type();
    Token * tok = this->look;
    match(Token::ID);
    match(';');
    Id * id = new Id( (Word *)(tok), p, this->used);
    this->top->put( tok, id );
    this->used = this->used + p->width;
  }
}

Type * Parser::type() {
  Type * p = (Type *)(this->look);
  match(Token::BASIC);
  return p;
}

Stmt * Parser::stmts() {
  if (this->look->getTag() == '}') {
    return Stmt::Null;
  } else {
    Stmt * s1 = stmt();
    Stmt * s2 = stmts();
    return new Seq(s1, s2);
  }
}

Stmt * Parser::stmt() {
  Expr * x;
  Stmt * s, * s1, * s2, * savedStmt;
  While * whilenode;

  switch( this->look->getTag() ) {
    case ';':
      this->move();
      return Stmt::Null;

    case Token::IF:
      match(Token::IF);
      match('(');
      x = boolean();
      match(')');
      s1 = stmt();
      if( this->look->getTag() != Token::ELSE )
        return new If(x, s1);
      match(Token::ELSE);
      s2 = stmt();
      return new Else(x, s1, s2);

    case Token::WHILE:
		whilenode = new While();
		savedStmt = Stmt::Enclosing;
		Stmt::Enclosing = whilenode;
		match(Token::WHILE);
		match('(');
		x = boolean();
		match(')');
		s1 = stmt();
		whilenode->init(x, s1);
		//Stmt::Enclosing = s savedStmt;
		return whilenode;
	
    case '{':
      return block();

    default:
      return assign();
  }

}

Stmt * Parser::assign() {
  Stmt * stmt  = NULL; 
  Token * t = this->look;
  match(Token::ID);
  Id * id = this->top->get(t);
  if( id == NULL )
    this->error(t->toString() + " no declarado");

  if(this->look->getTag() == (int) '=') {
    this->move(); 
  Expr * boolean1 = boolean();
	stmt = new Set(id, boolean1);
  }
  match(';');
  return stmt;
}

Expr * Parser::boolean() {
	Expr * x;
	x = join();
	while ( this->look->getTag() == Token::OR ) {
		Token * tok = this->look;
		this->move();
		x = new Or(tok, x, join());
	}
	return x;
}

Expr * Parser::join() {
  Expr * x;
  x = equality();
	while(this->look->getTag() == Token::AND){
		Token * tok = look;
		this->move();
		x = new And(tok, x, equality());
	}
	return x;
}

Expr * Parser::equality() {
  Expr * x;
  x = rel();

	while( this->look->getTag() == Token::EQ || this->look->getTag() == Token::NE ){
		Token * tok = look;
		this->move();
		x = new Rel(tok, x, rel());
	}
	
	return x;
}

Expr * Parser::rel() {
  Expr * x;
  x = expr();
  Token * tok;
  switch ( this->look->getTag() ) {
    case (int)'<':
    case Token::LE:
    case Token::GE:
    case (int)'>':
      tok = this->look;
      this->move();
      return new Rel(tok, x, expr());
    default:
      return x;
  }
}

Expr * Parser::expr() {
  Expr * x;
  x = term();
	while(this->look->getTag() == (int)'+' || this->look->getTag() == (int)'-'){
		//printf("Entro expr:\n x1:%s tok: %c ", x->toString().c_str(),(char) this->look->getTag());
		Token * tok = look;
		this->move();
		x = new Arith(tok, x, term());
	}
	return x;
}

Expr * Parser::term() {
  Expr * x;
  x = unary();
	while(this->look->getTag() == (int)'*' || this->look->getTag() == (int)'/'){
		Token * tok = look;
		this->move();
		x = new Arith(tok, x, unary());
	}
	return x;
}

Expr * Parser::unary() {
  if ( this->look->getTag() == (int)'-') {
    move();
    return new Unary(Word::Minus, unary());
  }
  return factor();
}

Expr * Parser::factor() {
	Expr * x;
	x = NULL;
	switch( this->look->getTag() ) {
		case (int)'(':
    {
			this->move();
			x = boolean();
			match(')');
			return x;
    }
		case Token::NUM:
    {
			x = new Constant(this->look, Type::Int);
			this->move();
			return x;
		}
		case Token::TRUE:
    {
			x = (Expr *) Constant::True;
			this->move();
			return x;
		}
		case Token::FALSE:
    {
			x = (Expr *) Constant::False;
			this->move();
			return x;
		}			
		case Token::ID:
		{
			std::string s;
			s = this->look->toString();
			Id *id = this->top->get(this->look);
			if(id == NULL){
				this->error(s + " no esta declarado.");
			}
			this->move();
			return id;
		}

    default:
    {
      this->error("Error de sintaxis");
      return x;
    }
      
	}

}
/* GRAMMAR METHODS */

void Parser::match(int t) {
  if(look->getTag() == t) this->move();
  else error("Syntax Error");
}

void Parser::error(std::string const &s) {
  fprintf(stderr, "Error en linea %d: %s\n", this->lex->line, s.c_str());
}

