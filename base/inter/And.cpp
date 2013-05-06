#include "And.hh"

And::And(Token *tok, Expr *x1, Expr *x2)
    :Logical(tok, x1, x2)
{
}

And::~And()
{
}

void And::jumping(int t, int f)
{
    int label;
    if(f != 0){
        label = f;
    }else{
        label = this->newlabel();
    }
    
    this->expr1->jumping(0, label);
    this->expr2->jumping(t, label);
    
    if(f==0){
        this->emitlabel(label);
    }
}