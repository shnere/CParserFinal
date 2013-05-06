#include "Type.hh"

int width = 0;
Type * Type::Int = new Type("int", Token::BASIC, 4);
Type * Type::Bool = new Type("bool", Token::BASIC, 1);

Type::Type(std::string const &s, int tag, int w)
  : Word(s,tag)
{
	this->width = w;
}

Type::~Type()
{
}

bool Type::numeric(Type *p)
{
	if (p->lexeme.compare(Type::Int->lexeme) == 0){
		return true;
	}
	return false;
}

Type * Type::max(Type *p1, Type *p2)
{
	if(! numeric(p1) || ! numeric(p2)){
		return NULL;
	}else{
		return Type::Int;
	}
}