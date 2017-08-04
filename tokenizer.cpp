#include "tokenizer.h"

Tokenizer::Tokenizer()
{
    _input="";
    variableType=0;
}
Tokenizer::Tokenizer(string input)
{
    _input=input;
    variableType=0;
}

myQueue<Token*> Tokenizer::stokenize()
{
    cout<<"input: "<<_input<<endl;
    myQueue<Token*> output;
    stringstream ss;
    ss<<_input;

    string token;
    ss>>token;
    if(token=="x")
    {
        // x=....
        variableType=1;
    }
    else if(token=="y")
    {
        variableType=0;
    }
    else
    {
        throw 0;
    }
    ss>>token;// suppose to be = sign
    if(token!="=" )
    {
        throw 0;
    }
    ss>>token;//tokens after the = sign

    while(token!="END")
    {
        //cout<<"token: "<<token<<endl;
        if(isdigit(token[0]) || isdigit(token[1]) || token=="x" || token=="y")
        {
            //integer
            output.add(new Integer(token));
        }
        else if(token=="+" || token=="-" || token=="*"|| token=="/" || token=="^")
        {
            //operator
            output.add(new Operator(token));
        }
        else if(token=="(" )
        {
            //left paren
            output.add(new LeftParen(token));
        }
        else if(token==")" )
        {
            //right paren
            output.add(new RightParen(token));
        }
        else if(token=="sin" || token=="cos" || token=="tan" || token=="max" || token=="min" || token=="pow")
        {
            //function
            output.add(new Function(token));
        }
        else
        {
            //cannot recognize
            throw 0;
        }
        ss>>token;
    }
    return output;
}
int Tokenizer::getValueType()
{
    return variableType;
}

