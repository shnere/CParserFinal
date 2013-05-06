#ifndef UNARY_HH_
#  define UNARY_HH_

#  include "Op.hh"

class Unary : public Op
{
  public:
    Unary(Token * tok, Expr * x);
    ~Unary();
    Expr * expr;
    Expr * gen();
    std::string const toString() const;
};

#endif /* !UNARY_HH_ */
