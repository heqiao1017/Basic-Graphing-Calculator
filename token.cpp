#include "token.h"

Token::Token()
{
    _input="";

}

Token::Token(string token)
{
    _input=token;
}

int Token::Type()
{
    return -1;
}

void Token::Print(ostream &outs)
{
    outs<<_input;
}

ostream& operator << (ostream& outs, Token& a_token)
{
    a_token.Print(outs);
    return outs;
}
string Token::getInput()
{
    return _input;
}
