#include <sstream>
#include "Num.hh"

Num::Num(int v)
  : Token((int)Token::NUM)
{
  this->value = v;
}

Num::~Num()
{
}

std::string const Num::toString()
{
  std::ostringstream buff;

  buff << this->value;
  return ("" + buff.str());
  buff.str("");
}

int Num::getValue() const
{
  return (this->value);
}
