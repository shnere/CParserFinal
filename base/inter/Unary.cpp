#include "Unary.hh"

Unary::Unary(Token * tok, Expr * x)
: Op(tok, NULL)
{
    this->expr = x;
    const Type * type = Type::max(Type::Int, this->expr->type);
    if(type == NULL)
      this->error("Unary type error");

}
Unary::~Unary()
{
}

std::string const Unary::toString() const
{
    return this->op->toString()+" "+this->expr->toString();
}