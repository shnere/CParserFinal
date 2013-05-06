#ifndef WORD_HH_
#  define WORD_HH_

#  include "Token.hh"


class Word : public Token
{

  public:
    Word(std::string const &s, int tag);
    virtual ~Word();    
    std::string const toString() const;
    void printMyData();
    static Word *And;
    static Word *Or;
    static Word *eq;
    static Word *ne;
    static Word *le;
    static Word *ge;
    static Word *Minus;
    static Word *True;
    static Word *False;
    static Word *Int;
    static Word *temp;
    
  protected:
    std::string lexeme;
};

#endif /* !WORD_HH_ */
