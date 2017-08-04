#ifndef FUNCTION_H
#define FUNCTION_H
#include "token.h"
class Function:public Token
{
public:
    Function();
    Function(string input);
    int Type();
    void Print(ostream &outs);
    string getInput();
private:
    string _input;
};

#endif // FUNCTION_H
