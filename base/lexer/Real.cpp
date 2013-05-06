#include <sstream>
#include "Real.hh"

Real::Real(float v)
  : Token((int)Token::REAL)
{
  this->value = v;
}

Real::~Real()
{
}

std::string const Real::toString()
{
  std::ostringstream buff;

  buff << this->value;
  return ("" + buff.str());
  buff.str("");
}

float Real::getValue() const
{
  return (this->value);
}
