#include "While.hh"

std::stringstream while_buffer;

While::While()
{
	this->expr = NULL;
	this->stmt = NULL;
}

While::~While()
{
}

void While::init(Expr *x, Stmt *s)
{
    this->expr = x;
    this->stmt = s;
    if( this->expr->type != Type::Bool ){
        this->expr->error("boolean required in while");
    }
}

void While::gen(int b, int a)
{
    this->after = a;
    expr->jumping(0, a);
    int label = newlabel();
    emitlabel(label);
    stmt->gen(label, b);
	while_buffer << b;
    emit("goto L"+ while_buffer.str());
	while_buffer.str("");
}