#ifndef INTEGER_H
#define INTEGER_H
#include "token.h"

class Integer: public Token
{
public:
    Integer();
    Integer(string input);
    int Type();
    void Print(ostream &outs);
    string getInput();
    double getInputNum();
private:
    double _inputNum;
    string _input;
};

#endif // INTEGER_H
