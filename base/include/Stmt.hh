#ifndef STMT_HH_
#  define STMT_HH_
#  include <string>
#  include "Node.hh"

class Stmt : public Node
{
  public:
    Stmt();
    ~Stmt();
    static Stmt * Null;
    static Stmt * Enclosing;
    virtual void gen(int b, int a); // Labels to Begin & After

  protected:
    int after;

};

#endif /* !STMT_HH_ */
