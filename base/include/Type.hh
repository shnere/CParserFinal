#ifndef TYPE_HH_
#  define TYPE_HH_

#  include "Token.hh"
#  include "Word.hh"

class Type : public Word
{
  public:
	int width;
	static Type * Int;
	static Type * Bool;
	Type(std::string const &s, int tag, int w);
	~Type();
	static bool numeric(Type *p);
	static Type * max(Type *p1, Type *p2);
};

#endif /* !TYPE_HH_ */
