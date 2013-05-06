#include "Rel.hh"

Rel::Rel(Token *tok, Expr *x1, Expr *x2)
    :Logical(tok, x1, x2)
{
}

Rel::~Rel()
{
}

void Rel::jumping(int t, int f)
{
    int label;
    if(t != 0){
        label = t;
    }else{
        label = this->newlabel();
    }
    
    this->expr1->jumping(label, 0);
    this->expr2->jumping(t, f);
    
    if(t==0){
        this->emitlabel(label);
    }
}