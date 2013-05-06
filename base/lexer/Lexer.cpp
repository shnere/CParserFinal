#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>
#include "Lexer.hh"
#include "Token.hh"
#include "Num.hh"
#include "Real.hh"
#include "Word.hh"
#include "Type.hh"

Lexer::Lexer()
{
  this->line = 1;
  this->peek = ' ';
  this->words = std::map<std::string, Word *>();
  this->reserve(new Word("if", Token::IF));
  this->reserve(new Word("else", Token::ELSE));
  this->reserve(new Word("while", Token::WHILE));
  this->reserve(Word::True);
  this->reserve(Word::False);
  this->reserve(Type::Int);
  this->reserve(Type::Bool);
  this->readch(); //i
  this->readch(); //n
  this->readch(); //t
  this->readch(); // 
  this->readch(); //m
  this->readch(); //a
  this->readch(); //i
  this->readch(); //n
  this->readch(); //(
  this->readch(); //)
  this->readch(); // :)
}

Lexer::~Lexer()
{
  delete Word::And;
  delete Word::Or;
  delete Word::eq;
  delete Word::ne;
  delete Word::le;
  delete Word::ge;
  delete Word::Minus;
  delete Word::True;
  delete Word::False;
  delete Word::temp;
}

void Lexer::printMap(std::string key)
{
  printf("%s: %s\n", key.c_str(), (Word *)(this->words.find(key)->second)->toString().c_str());
}

void Lexer::reserve(Word *w)
{
  this->words.insert(std::pair<std::string, Word *>(w->toString(), w));
}

void Lexer::readch()
{
  this->peek = getchar();
}

bool Lexer::readch(char c)
{
  this->readch();
  if (this->peek != c)
    return (false);
  this->peek = ' ';
  return (true);
}

Token *Lexer::scan()
{
  for ( ; ; this->readch())
  {
    if (this->peek == ' ' || this->peek == '\t')
      continue;
    else if (this->peek == '\n')
      this->line++;
    else
      break;
  }
  switch (this->peek)
  {
	//printf("Leo %c\n", this->peek);
    case '&':
      if (this->readch('&'))
        return Word::And;
      else
        return (new Token('&'));
    case '|':
      if (this->readch('|'))
        return Word::Or;
      else
        return (new Token('|'));
    case '=':
      if (this->readch('='))
        return Word::eq;
      else
        return (new Token('='));
    case '!':
      if (this->readch('='))
        return Word::ne;
      else
        return (new Token('!'));
    case '<':
      if (this->readch('='))
        return Word::le;
      else
        return (new Token('<'));
    case '>':
      if (this->readch('='))
        return Word::ge;
      else
        return (new Token('>'));
  }

	if(isdigit(this->peek) != 0){
		int v = 0;
		do{
			v = 10*v + atoi(&peek); 
			this->readch();
		}while( isdigit(this->peek) != 0);
		
		if(strcmp(&this->peek, ".")){
			Num *n = new Num(v);
			return n; 
		}
		float x = v, d = 10;
		for(;;){
			this->readch();
			if(isdigit(peek) == 0) break;
			x = x + atoi(&peek) / d;
			d *= 10;	
		}
		Real *r = new Real(x);
		return r;
	}
	
	if( ( this->peek >= 65 && this->peek <= 90 ) || //A-Z
      ( this->peek >= 97 && this->peek <= 122) ){ //a-z
		std::string buffer;
		do{
			buffer.append(&peek);
			this->readch();
		}while(isalnum(peek) != 0);
		
		Word *w;
		if (this->words.find(buffer) == this->words.end()){
			w = NULL;
		} else{
			w = (Word *)(this->words.find(buffer)->second);
		}
		
		if( w != NULL ) {
			return w;
    	}
		
		w = new Word(buffer, Token::ID);
		words.insert(std::pair<std::string, Word *>(buffer, w));
    //w->printMyData();
		return w;
	}
	Token *tok = new Token(this->peek);
	this->peek = ' ';
	return tok;

}
