#include "leftparen.h"

LeftParen::LeftParen()
{
    _input="";
}

LeftParen::LeftParen(string input)
{
    _input=input;
}

int LeftParen::Type()
{
    return 1;
}

void LeftParen::Print(ostream &outs)
{
    outs<<_input;
}
string LeftParen::getInput()
{
    return _input;
}
