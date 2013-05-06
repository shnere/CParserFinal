#ifndef ELSE_HH_
#define ELSE_HH_
#include <sstream>
#include "Expr.hh"
#include "Stmt.hh"
#include "Type.hh"


class Else: public Stmt
{
    public:
        Else(Expr *x, Stmt *s1, Stmt *s2);
        ~Else();
        void gen(int b, int a);
        Expr * expr;
        Stmt * stmt1;
        Stmt * stmt2;
};

#endif /* !ELSE_HH_ */