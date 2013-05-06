#ifndef OR_HH_
#  define OR_HH_
#include "Logical.hh"

class Or: public Logical
{
    public:
        Or(Token *tok, Expr *x1, Expr *x2);
        ~Or();
        void jumping(int t, int f);
        
};

#endif /* !OR_HH_ */