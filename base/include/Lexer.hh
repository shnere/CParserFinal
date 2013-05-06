#ifndef LEXER_HH_
#  define LEXER_HH_

#  include <map>
#  include "Token.hh"
#  include "Word.hh"

class Lexer
{
  public:
    Lexer();
    ~Lexer();
    Token *scan();
    friend class Parser;

  protected:
    int line;
    char peek;
    std::map<std::string, Word *> words;
    void reserve(Word *w);
    void readch();
    bool readch(char c);
    void printMap(std::string key);
};

#endif /* !LEXER_HH_ */
