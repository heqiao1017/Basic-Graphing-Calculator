//QIAO HE
//final project
//5/5/2016

#include <iostream>
#include "tokenizer.h"
#include "topostfix.h"
#include "generatepoints.h"
#include "game.h"
using namespace std;
void test();
int main()
{
    Game myGame;
    myGame.run();
    //test();
    return 0;
}
void test()
{
    string input="y = tan x / ( sin x ) + ( 100 - x ^ 2 ) ^ ( 1 / 2 ) END";
    Tokenizer t(input);
    myQueue<Token*>  prefix, postfix;
    prefix=t.stokenize();
    prefix.PrintMe();
    ToPostfix shuntingyard;
    cout<<"before convert"<<endl;
    postfix=shuntingyard.convert(prefix);
    cout<<"after convert"<<endl;
    postfix.PrintMe();
    double result=shuntingyard.Evaluate(postfix, 0);
    cout<<"result: "<<result<<endl;
}
