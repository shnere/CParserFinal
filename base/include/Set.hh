#ifndef SET_HH_
#define SET_HH_
#include "Stmt.hh"
#include "Type.hh"
#include "Id.hh"
#include "Expr.hh"


class Set: public Stmt
{
    public:
        Set(Id *i,  Expr *x);
        ~Set();
        Type * check(Type *p1, Type *p2);
        void gen(int b, int a);
        Id * id;
        Expr * expr;
};

#endif /* !SET_HH_ */