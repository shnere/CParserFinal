#include "Node.hh"

int Node::labels;

Node::Node()
{
  this->lexline = 0;
  Node::labels = 0;
}

Node::~Node()
{
}

void Node::error(std::string const &s)
{
  fprintf(stderr, "Error en linea %d: %s\n", this->lexline, s.c_str());
}

int Node::newlabel() {
  return ++Node::labels;
}

void Node::emitlabel(int i) {
  fprintf(stdout, "L%d:", i);
}

void Node::emit(std::string const &s)
{
  fprintf(stdout, "\t%s\n", s.c_str());
}