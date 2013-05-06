#include "Arith.hh"
#include "Type.hh"


Arith::Arith(Token *tok, Expr *x1, Expr *x2)
  :Op(tok, NULL)
{
    this->expr1 = x1;
    this->expr2 = x2;
    this->type = Type::max(this->expr1->type, this->expr2->type);
    if(type == NULL){
        this->error("error tipo");
    }
}

Arith::~Arith()
{
}

Expr * Arith::gen()
{
    Arith * a = new Arith(this->op, this->expr1->reduce(), this->expr2->reduce());
    return a;
}

std::string const Arith::toString()
{
    return this->expr1->toString()+" "+this->op->toString()+" "+this->expr2->toString();
}