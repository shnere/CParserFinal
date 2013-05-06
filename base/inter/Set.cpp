#include <sstream>
#include "Set.hh"

Set::Set(Id *i,  Expr *x)
{
    this->id = i; 
    this->expr = x;
    if ( expr->type != NULL && id->type != NULL && check(id->type, expr->type) == NULL ){
        error("type error");
    }
}

Set::~Set()
{
}

Type * Set::check(Type *p1, Type *p2){
    if(Type::numeric(p1) && Type::numeric(p2)){
        return p2;
    } else if(p1 == Type::Bool && p2 == Type::Bool){
        return p2;
    } else{
        return NULL;
    }
}

void Set::gen(int b, int a)
{
    std::ostringstream set_buff;
    set_buff << this->id->toString() << " = " << this->expr->gen()->toString();
    emit(  set_buff.str() );
    set_buff.str("");
}