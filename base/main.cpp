#include <string.h>
#include <stdio.h>
#include "Lexer.hh"
#include "Parser.hh"

int main() {
  Lexer *lex = new Lexer();
  Parser *parse = new Parser(&lex);
  parse->program();
  return 0;
}