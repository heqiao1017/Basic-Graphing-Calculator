#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include "token.h"

class RightParen:public Token
{
public:
    RightParen();
    RightParen(string input);
    int Type();
    void Print(ostream &outs);
    string getInput();
private:
    string _input;
};

#endif // RIGHTPAREN_H
