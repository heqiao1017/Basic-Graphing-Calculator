#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include "token.h"

class LeftParen:public Token
{
public:
    LeftParen();
    LeftParen(string input);
    int Type();
    void Print(ostream &outs);
    string getInput();
private:
    string _input;
};

#endif // LEFTPAREN_H
