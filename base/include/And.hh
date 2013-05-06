#ifndef AND_HH_
#  define AND_HH_
#include "Logical.hh"

class And: public Logical
{
    public:
        And(Token *tok, Expr *x1, Expr *x2);
        ~And();
        void jumping(int t, int f);
        
};

#endif /* !AND_HH_ */