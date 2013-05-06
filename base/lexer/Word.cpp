#include "Word.hh"

Word * Word::And = new Word("&&", Token::AND);
Word * Word::Or = new Word("||", Token::OR);
Word * Word::eq = new Word("==", Token::EQ);
Word * Word::ne = new Word("!=", Token::NE);
Word * Word::le = new Word("<=", Token::LE);
Word * Word::ge = new Word(">=", Token::GE);
Word * Word::Minus = new Word("minus", Token::MINUS);
Word * Word::True = new Word("true", Token::TRUE);
Word * Word::False = new Word("false", Token::FALSE);
Word * Word::temp = new Word("t", Token::TEMP);

Word::Word(std::string const &s, int tag)
  : Token(tag)
{
  this->lexeme = s;
}

Word::~Word()
{
}

std::string const Word::toString() const
{
  return (this->lexeme);
}

void Word::printMyData() {
//  printf("Lexeme: %s\nTag: %d\n", this->lexeme.c_str(), this->tag);
}
