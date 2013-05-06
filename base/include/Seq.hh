#ifndef SEQ_HH_
#define SEQ_HH_
#include "Stmt.hh"

class Seq: public Stmt
{
    public:
        Seq(Stmt *s1, Stmt *s2);
        ~Seq();
        void gen(int b, int a);
        Stmt * stmt1;
        Stmt * stmt2;
        
};

#endif /* !SEQ_HH_ */