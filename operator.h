#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"

class Operator:public Token
{
public:
    Operator();
    Operator(string input);
    int Type();
    void Print(ostream &outs);
    string getInput();
    int getPrecedence();
private:
    string _input;
    int _precedence;
};

#endif // OPERATOR_H
