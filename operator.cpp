#include "operator.h"

Operator::Operator()
{
    _input="";
    _precedence=0;
}

Operator::Operator(string input)
{
    _input=input;
    if(_input=="+" || _input=="-")
    {
        _precedence=1;
    }
    else if(_input=="*" || _input=="/")
    {
        _precedence=2;
    }
    else if(_input=="^")
    {
        _precedence=3;
    }
}

int Operator::Type()
{
    return 2;
}
string Operator::getInput()
{
    return _input;
}

void Operator::Print(ostream &outs)
{
    outs<<_input;
}

int Operator::getPrecedence()
{
    return _precedence;
}

