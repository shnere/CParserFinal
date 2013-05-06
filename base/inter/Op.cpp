#include "Op.hh"

Op::Op(Token * tok, Type * p)
	: Expr(tok, p)
{
}

Op::~Op(){
}

Expr * Op::reduce(){
	Expr * x = Expr::gen();
	Temp * t = new Temp(this->type);
	//Node::emit(t->toString() + " = "+ x->toString());
	Node::emit("( = "+ x->toString() + ", , " + t->toString() + ")");
	return t;
}
