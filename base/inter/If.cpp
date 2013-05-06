#include "If.hh"

If::If(Expr *x, Stmt *s)
{  
    this->expr = x;
    this->stmt = s;
    if( this->expr->type != Type::Bool ){
        this->error("boolean required in if");
    }
}

If::~If()
{
}

void If::gen(int b, int a)
{
      int label = this->newlabel(); // label for the code for stmt
      this->expr->jumping(0, a);     // fall through on true, goto a on false
      this->emitlabel(label); 
      this->stmt->gen(label, a);
}
