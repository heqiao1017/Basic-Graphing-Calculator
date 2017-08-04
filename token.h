#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

class Token
{
public:
    Token();
    Token(string token);
    virtual int Type();
    virtual void Print(ostream& outs);
    friend ostream& operator << (ostream& outs, Token& a_token);
    virtual string getInput();
private:
    string _input;
};

#endif // TOKEN_H
