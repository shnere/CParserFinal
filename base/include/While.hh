#ifndef WHILE_HH_
#define WHILE_HH_
#include "Expr.hh"
#include "Stmt.hh"
#include "Type.hh"
#include <string>
#include <sstream>

class While: public Stmt
{
    public:
        While();
        ~While();
        void init(Expr *x, Stmt *s);
        void gen(int b, int a);
        Expr *expr;
        Stmt *stmt;
};

#endif /* !WHILE_HH_ */