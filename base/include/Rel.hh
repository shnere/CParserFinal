#ifndef REL_HH_
#  define REL_HH_
#include "Logical.hh"

class Rel: public Logical
{
    public:
        Rel(Token *tok, Expr *x1, Expr *x2);
        ~Rel();
        void jumping(int t, int f);
        
};

#endif /* !REL_HH_ */