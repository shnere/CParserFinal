#ifndef LOGICAL_HH_
#  define LOGICAL_HH_
#include "Expr.hh"
#include <sstream>

class Logical: public Expr
{
    public:
        Logical(Token *tok, Expr *x1, Expr *x2);
        ~Logical();
        Type * check(Type *p1, Type *p2);
        Expr * gen();
        std::string const toString();
        Expr * expr1;
        Expr * expr2;
        
};

#endif /* !LOGICAL_HH_ */