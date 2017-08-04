#include "rightparen.h"

RightParen::RightParen()
{
    _input="";
}

RightParen::RightParen(string input)
{
    _input=input;
}

int RightParen::Type()
{
    return 3;
}
void RightParen::Print(ostream &outs)
{
    outs<<_input;
}
string RightParen::getInput()
{
    return _input;
}
