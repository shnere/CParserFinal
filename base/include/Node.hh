#ifndef NODE_HH_
#  define NODE_HH_
#  include <string>

class Node
{
  public:
    Node();
    ~Node();
    static int labels;
    int newlabel();
    void emitlabel(int i);
    void emit(std::string const &s);
    void error(std::string const &s);

  protected:
    int lexline;
    
};

#endif /* !NODE_HH_ */
