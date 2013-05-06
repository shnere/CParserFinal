#include "Stmt.hh"

Stmt * Stmt::Null = new Stmt();
Stmt * Stmt::Enclosing = Stmt::Null;

Stmt::Stmt()
{
  this->after = 0;
}

Stmt::~Stmt()
{
}

void Stmt::gen(int b, int a) {}