#ifndef PARSER_HH_
#  define PARSER_HH_
#  include "Lexer.hh"
#  include "Node.hh"
#  include "Stmt.hh"
#  include "Seq.hh"
#  include "Expr.hh"
#  include "Id.hh"
#  include "While.hh"
#  include "Or.hh"
#  include "Constant.hh"
#  include "Token.hh"
#  include "If.hh"
#  include "Else.hh"
#  include "Unary.hh"
#  include "Set.hh"
#  include "And.hh"
#  include "Rel.hh"
#  include "Arith.hh"
#  include "Env.hh"

class Parser
{
  public:
    Parser(Lexer ** l);
    ~Parser();
    void program();

  protected:
    Lexer* lex;
    Token* look;
    Env * top;
    int used;


  private:
    void move();
    
    void match(int t);
    void error(std::string const &s);

    /* Grammar Methods */
    Stmt * block();
    void decls();
    Type * type();
    Stmt * stmts();
    Stmt * stmt();
    Stmt * assign();
    Expr * boolean();
    Expr * join();
    Expr * equality();
    Expr * rel();
    Expr * expr();
    Expr * term();
    Expr * factor();
    Expr * unary();


};

#endif /* !PARSER_HH_ */
