#include "Else.hh"

std::ostringstream else_buff;

Else::Else(Expr *x, Stmt *s1, Stmt *s2)
{  
    this->expr = x;
    this->stmt1 = s1;
    this->stmt2 = s2;
    if( this->expr->type != Type::Bool ){
        this->error("boolean required in if");
    }
}

Else::~Else()
{
}

void Else::gen(int b, int a)
{
      int label1 = this->newlabel();
      int label2 = this->newlabel();
      this->expr->jumping(0, label2);     
      
      this->emitlabel(label1);
      this->stmt1->gen(label1, a);

      else_buff << a;
      this->emit("goto L" + else_buff.str());
      else_buff.str("");
      
      this->emitlabel(label2);
      this->stmt1->gen(label2, a);
   
}
