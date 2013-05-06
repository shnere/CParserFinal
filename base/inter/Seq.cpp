#include "Seq.hh"

Seq::Seq(Stmt *s1, Stmt *s2)
{
    this->stmt1 = s1;
    this->stmt2 = s2;
}

Seq::~Seq()
{
}

void Seq::gen(int b, int a)
{
    if ( this->stmt1 == Stmt::Null ){
        this->stmt2->gen(b, a);  
    }else if ( stmt2 == Stmt::Null ) {
        this->stmt1->gen(b, a);   
    }else {
         int label = newlabel();
         this->stmt1->gen(b,label);
         emitlabel(label);
         this->stmt2->gen(label,a);
      }
    
}