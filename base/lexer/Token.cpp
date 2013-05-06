#include <sstream>
#include "Token.hh"

Token::Token(int t)
{
  this->tag = t;
}

Token::~Token()
{
}

int Token::getTag() const
{
  return (this->tag);
}

std::string const Token::toString()
{
  // std::ostringstream token_buff;
  // token_buff << this->tag;
  // return token_buff.str();
  return ("" + (static_cast<char>(this->tag)));
}
