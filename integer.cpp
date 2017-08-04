#include "integer.h"

Integer::Integer()
{
    _inputNum=0;
    _input="";
}

Integer::Integer(string input)
{
    _input=input;
    if(input!="x" && input!="y")
    {
        _inputNum=atof(_input.c_str());
    }
    else
    {
        _inputNum=0;
    }
}

int Integer::Type()
{
    return 0;
}

void Integer::Print(ostream &outs)
{
    outs<<_input;
}

string Integer::getInput()
{
    return _input;
}

double Integer::getInputNum()
{
    return _inputNum;
}
