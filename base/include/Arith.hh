#ifndef ARITH_HH_
#  define ARITH_HH_
#include "Expr.hh"
#include "Op.hh"

class Arith: public Op
{
    public:
        Arith(Token *tok, Expr *x1, Expr *x2);
        ~Arith();
        Expr * gen();
        std::string const toString();
        Expr * expr1;
        Expr * expr2;
        
};

#endif /* !ARITH_HH_ */