#ifndef ENV_HH_
#  define ENV_HH_

#  include <map>
#  include "Token.hh"
#  include "Id.hh"

class Env
{
  public:
    Env(Env * n);
    ~Env();
    void put(Token * w, Id * i);
    Id * get(Token * w);

  protected:
    Env * prev;
    std::map<Token *, Id *> table;
};

#endif /* !ENV_HH_ */
