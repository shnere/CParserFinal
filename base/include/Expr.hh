#ifndef EXPR_HH_
# define EXPR_HH_
# include <string>
# include "Node.hh"
# include "Token.hh"
# include "Type.hh"

class Expr: public Node
{
	public: 
		Expr(Token * tok, Type * p);
		~Expr();
		Expr * gen();
		Expr * reduce();
		void jumping(int t, int f);
		void emitjumps(std::string const &s, int t, int f);
		std::string const toString();
		Token * op;
		Type * type;
};

#endif /* !EXPR_HH_ */