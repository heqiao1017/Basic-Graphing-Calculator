#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "../../../../Stack_and_Queue/Stack_and_Queue/myqueue.h"
#include "integer.h"
#include "operator.h"
#include "leftparen.h"
#include "rightparen.h"
#include "function.h"
#include <sstream>
class Tokenizer
{
public:
    Tokenizer();
    Tokenizer(string input);

    myQueue<Token*> stokenize();

    //get the variable type
    int getValueType();

private:
    string _input;
    int variableType;// 0: x is the variable; 1: y is the variable
};

#endif // TOKENIZER_H
