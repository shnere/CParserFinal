#ifndef NUM_HH_
#  define NUM_HH_

#  include "Token.hh"

class Num: public Token
{
  public:
    Num(int v);
    ~Num();
    std::string const toString();
    int getValue() const;

  protected:
    int value;
};


#endif /* !NUM_HH_ */
