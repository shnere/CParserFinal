#ifndef TEMP_HH_
#define TEMP_HH_
#include "Expr.hh"
#include "Type.hh"

class Temp: public Expr
{
    public:
        Temp(Type *p);
        ~Temp();
        std::string const toString();
        int count;
        int number;
};

#endif /* !TEMP_HH_ */