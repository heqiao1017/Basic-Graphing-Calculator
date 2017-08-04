#ifndef TOPOSTFIX_H
#define TOPOSTFIX_H
#include "../../../../Stack_and_Queue/Stack_and_Queue/myqueue.h"
#include "../../../../Stack_and_Queue/Stack_and_Queue/mystack.h"
#include "token.h"
#include "operator.h"
#include "integer.h"
#include <math.h>
class ToPostfix
{
public:
    ToPostfix();

    //convert prefix list to postfix list
    myQueue<Token*> convert(myQueue<Token *> &tokenList);

    //evaluate the postfix
    double Evaluate(myQueue<Token *>& postfixList, double value);
};

#endif // TOPOSTFIX_H
