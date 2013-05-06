#include "Or.hh"

Or::Or(Token *tok, Expr *x1, Expr *x2)
    :Logical(tok, x1, x2)
{
}

Or::~Or()
{
}

void Or::jumping(int t, int f)
{
    int label;
    if(t != 0){
        label = t;
    }else{
        label = this->newlabel();
    }
    
    this->expr1->jumping(0, label);
    this->expr2->jumping(t, f);
    
    if(t==0){
        this->emitlabel(label);
    }
}