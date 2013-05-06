#include <sstream>
#include "Expr.hh"

std::stringstream out;

Expr::Expr(Token * tok, Type * p)
{
  this->op = tok;
  this->type = p;
}

Expr::~Expr()
{
}

Expr * Expr::gen()
{
	return this;
}

Expr * Expr::reduce()
{
	return this;
}
void Expr::jumping(int t, int f) {

	this->emitjumps( this->toString(), t, f);
}

void Expr::emitjumps(std::string const &test, int t, int f)
{
	if( t != 0 && f != 0){
    out << t;
		Node::emit("if "+ test +" goto "+ out.str());
    out.str("");

    out << f;
		Node::emit("goto L"+out.str());
    out.str("");
		
		}else if( t != 0){
      out << f;
			Node::emit("if "+ test +" goto L "+ out.str());
      out.str("");
		} else if ( f != 0){
      out << f;
			Node::emit("iffalse " + test + " goto L" + out.str());
      out.str("");
		}
}

std::string const Expr::toString()
{
  Word * w = dynamic_cast<Word *>(this->op);
  if(w != 0) {
    return w->toString();
  } else {
    return this->op->toString();
  }
}