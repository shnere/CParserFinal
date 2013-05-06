#ifndef CONSTANT_HH_
#  define CONSTANT_HH_

#   include "Expr.hh"
#   include "Token.hh"
#   include "Type.hh"
#   include "Num.hh"
#	include <sstream>

class Constant : public Expr
{
  public:
	static const Constant * True;
  static const Constant * False;
  Constant(Token *tok, Type *p);
  Constant(int i);
  ~Constant();
	void jumping(int i, int f);
};

#endif /* !CONSTANT_HH_ */