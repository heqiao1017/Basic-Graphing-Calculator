#include "function.h"

Function::Function()
{
    _input="";
}
Function::Function(string input)
{
    _input=input;
}

int Function::Type()
{
    return 4;
}

void Function::Print(ostream &outs)
{
    outs<<_input;
}

string Function::getInput()
{
    return _input;
}
