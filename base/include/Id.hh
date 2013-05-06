#ifndef ID_HH_
# define ID_HH_
# include "Expr.hh"
# include "Type.hh"

class Id: public Expr
{
	public: 
		Id(Word *id, Type *p, int b);
		~Id();
		
	protected:
		int offset;
};

#endif /* !ID_HH_ */