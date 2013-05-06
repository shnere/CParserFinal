#include "Id.hh"

Id::Id(Word * id, Type * p, int b)
  : Expr(id,p)
{
   this->offset = b;
}

Id::~Id()
{
}