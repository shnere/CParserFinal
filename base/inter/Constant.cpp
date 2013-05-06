#include <sstream>
#include "Constant.hh"

const Constant * Constant::True = new Constant(Word::True, Type::Bool);
const Constant * Constant::False = new Constant(Word::False, Type::Bool);

Constant::Constant(Token *tok, Type *p)
  : Expr(tok,p)
{
}

Constant::Constant(int i)
  : Expr(new Num(i), Type::Int)
{
}

void Constant::jumping(int t, int f)
{
    std::ostringstream constant_buff;
    if(this == True && t != 0){
		constant_buff << t;
        	emit("goto L"+constant_buff.str());
		constant_buff.str("");
    }else if(this == False && f != 0){
		constant_buff << f;
		emit("goto L"+constant_buff.str());
		constant_buff.str("");
    }
}
