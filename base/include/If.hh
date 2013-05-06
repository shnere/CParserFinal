#ifndef IF_HH_
#define IF_HH_
#include "Expr.hh"
#include "Stmt.hh"
#include "Type.hh"

class If: public Stmt
{
    public:
        If(Expr * x, Stmt * s);
        ~If();
        void gen(int a, int b);
        Expr * expr;
        Stmt * stmt;
};

#endif /* !IF_HH_ */