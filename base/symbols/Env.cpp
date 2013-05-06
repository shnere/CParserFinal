#include "Env.hh"

Env::Env(Env * n)
{
  this->prev = n;
  this->table = std::map<Token *, Id *>();
}

Env::~Env()
{
}

void Env::put(Token * w, Id * i) {
  //printf("***Inserting token to Env Table***\n");
  //((Word *)w)->printMyData();
  this->table.insert(std::pair <Token *, Id *>(w, i));
  //printf("***Finished insert to Env Table***\n");
}

Id * Env::get(Token * w) {
  //int a = 0;
  for( Env * e = this; e != NULL; e = e->prev ) {
    //printf("Loop number %d:\n", a++);
    //((Word *)w)->printMyData();
    Id * found = (Id *)(this->table.find(w)->second);

    if( found != NULL ) {
    //  printf("Id is not null mudafucka\n");
      return found;
    }

  }
  return NULL;
}