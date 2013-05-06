#include <sstream>
#include "Temp.hh"
#include "Word.hh"

int count = 0;
int number = 0;
std::ostringstream temp_buff;

Temp::Temp(Type *p)
:Expr(Word::temp, p)
{
    number = ++count;
}
Temp::~Temp()
{
}

std::string const Temp::toString()
{
  temp_buff << number;
  return "t" + temp_buff.str();
  temp_buff.str("");
}