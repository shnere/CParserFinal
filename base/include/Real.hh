#ifndef REAL_HH_
#  define REAL_HH_

#  include "Token.hh"

class Real: public Token
{
  public:
    Real(float v);
    ~Real();
    std::string const toString();
    float getValue() const;

  protected:
    float value;
};

#endif /* !REAL_HH_ */
