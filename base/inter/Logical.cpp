#include <sstream>
#include "Logical.hh"
#include "Type.hh"
#include "Temp.hh"

std::stringstream log_buffer;

Logical::Logical(Token *tok, Expr *x1, Expr *x2)
  :Expr(tok, NULL)
{
    this->expr1 = x1;
    this->expr2 = x2;
    this->type = this->check(this->expr1->type, this->expr2->type);
    if(type == NULL){
        this->error("error tipo");
    }
}

Logical::~Logical()
{
}

Type * Logical::check(Type *p1, Type *p2)
{
    if(p1 == Type::Bool && p2 == Type::Bool){
        return Type::Bool;
    }else {
        return NULL;
    }
}

Expr * Logical::gen()
{
    
    int f = newlabel(); 
    int a = newlabel();
    Temp * temp = new Temp(this->type);
    this->jumping(0,f);
    //emit(temp->toString() + " = true");
	emit("(=, true, " + temp->toString() + ")");
	log_buffer << a;
    emit("goto L" + log_buffer.str());
	log_buffer.str("");
    emitlabel(f); 
    //emit(temp->toString() + " = false");
	emit("(=, false, " + temp->toString() + ")");
    emitlabel(a);
    return temp;
}

std::string const Logical::toString()
{
    return this->expr1->toString()+" "+this->op->toString()+" "+this->expr2->toString();
    
}