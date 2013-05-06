#ifndef OP_HH_
# define OP_HH_
#include "Expr.hh"
#include "Token.hh"
#include "Type.hh"
#include "Temp.hh"

class Op: public Expr{
	
	public:
		Op(Token * tok, Type * p);
		~Op();
		Expr * reduce();
};

#endif /* !OP_HH_ */