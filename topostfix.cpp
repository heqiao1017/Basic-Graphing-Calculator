#include "topostfix.h"
#include "leftparen.h"
#include "rightparen.h"
#include <math.h>
ToPostfix::ToPostfix()
{}

myQueue<Token *> ToPostfix::convert(myQueue<Token*>& tokenList)
{
    myQueue<Token *> output;
    myStack<Token *> operatorList;

    while(!tokenList.Empty())
    {
        Token* token=tokenList.remove();
        cout<<"token: "<<token->getInput()<<endl;
        if(token->Type()==0)
        {
            //an integer
            output.add(token);
        }
        else if(token->Type()==4)
        {
            //function
            operatorList.Push(token);
        }
        else if(token->Type()==1)
        {
            //left paren
            operatorList.Push(token);
        }
        else if(token->Type()==2)
        {
            //an operator
            bool done=false;
            cout<<"before while"<<endl;
            while(!operatorList.Empty() && !done)
            {
                Token* top=operatorList.Top();//the top item in the stack

                cout<<"======================"<<endl;
                cout<<"top of the operator list: "<<top->getInput()<<endl;
                cout<<"======================"<<endl;

                //check if is is a paren before dynamic cast
                if(top->getInput()=="(")
                {
                    done=true;
                    operatorList.Push(token);
                    break;
                }

                //check if is functions
                if(top->Type()==4)
                {
                    //all functions have higher precedence
                    output.add(top);
                    operatorList.Pop();
                    break;
                }

    //******************************************************
    //the rest tokens inside the stack will be opertor tokens
    //******************************************************

                Operator* tokenOperator=dynamic_cast<Operator*>(token);
                cout<<"after dynamic cast from the token"<<endl;
                Operator* topOperator=dynamic_cast<Operator*>(top);
                cout<<"after dynamic cast from the top item in operator list"<<endl;

                                                                                                        //                cout << "op? " << dynamic_cast<Operator*>(top)<<endl;
                                                                                                        //                cout << "int? " << dynamic_cast<Integer*>(top)<<endl;
                                                                                                        //                cout << "(? " << dynamic_cast<LeftParen*>(top)<<endl;
                                                                                                        //                cout << ")? " << dynamic_cast<RightParen*>(top)<<endl;
                                                                                                        //                cout << "tokenOp: " << tokenOperator << endl;

                if(tokenOperator->getPrecedence() > topOperator->getPrecedence())
                {
                    operatorList.Push(token);
                    done=true;
                }
                while(!operatorList.Empty() && tokenOperator->getPrecedence()<=topOperator->getPrecedence())
                {
                    output.add(operatorList.Top());
                    operatorList.Pop();
                    if(!operatorList.Empty())
                    {
                        if(operatorList.Top()->getInput()=="(")
                        {
                            done=true;
                            operatorList.Push(token);
                            break;
                        }
                        if(operatorList.Top()->Type()==4)
                        {
                            //all functions have higher precedence
                            output.add(top);
                            operatorList.Pop();
                            break;
                        }
                        //replace the top operator with the new top
                        topOperator=dynamic_cast<Operator*>(operatorList.Top());
                    }
                }
            }
            if(!done)
            {
                operatorList.Push(token);
            }
        }
        else if(token->Type()==3)
        {
            //right paren
            while (!operatorList.Empty() && operatorList.Top()->getInput() != "(")
            {
                cout<<"popo until there is a leftParen"<<endl;
                output.add(operatorList.Top());
                operatorList.Pop();
            }
            operatorList.Pop();//remove the matching paren
        }
                                                                                                                        //        cout<<"Operator list: ";
                                                                                                                        //        operatorList.PrintMe();
                                                                                                                        //        cout<<"Output list: ";
                                                                                                                        //        output.PrintMe();
    }//when the tokenlist is not empty

    if(tokenList.Empty())
    {
        while(!operatorList.Empty())
        {
            //If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses
            if(operatorList.Top()->getInput()=="(")
            {
                cout<<"There is mismatched parenthese"<<endl;
                throw 0;
            }
            //Pop the operator onto the output queue
            Token* top=operatorList.Top();
            output.add(top);
            operatorList.Pop();
        }
    }
    return output;
}

double ToPostfix::Evaluate(myQueue<Token *>& postfixList, double value)
{
    myStack<Token *> numList;
    string input1, input2;
    double num1,num2,result;
    while(!postfixList.Empty())
    {
        Token* token=postfixList.remove();
        if(token->Type()==0)
        {
            //------->Integer
            numList.Push(token);
        }
        if(token->Type()==2)
        {
            //------->Operator

            //get the first number inside the number list
            if(!numList.Empty())
            {
                input1=numList.Pop()->getInput();
            }
            else
            {
                throw 0;//invalid equation
            }

            if(input1=="x" || input1=="y")
            {
                num1=value;
            }
            else
            {
                num1=atof(input1.c_str());
            }

            //get the second number inside the number list
            if(!numList.Empty())
            {
                input2=numList.Pop()->getInput();
            }
            else
            {
                throw 0;//invalid equation
            }

            if(input2=="x" || input2=="y")
            {
                num2=value;
            }
            else
            {
                num2=atof(input2.c_str());
            }


            //check what type of oeprator and calculate a new number based on the operator
            if(token->getInput()=="+")
            {
                result=num1+num2;
            }
            else if(token->getInput()=="-")
            {
                result=num2-num1;
            }
            else if(token->getInput()=="*")
            {
                result=num1*num2;
            }
            else if(token->getInput()=="/")
            {
                result=num2/num1;
            }
            else if(token->getInput()=="^")
            {
                result=pow(num2,num1);
            }

            numList.Push(new Integer(to_string(result)));//push the new number into the number list
        }
        if(token->Type()==4)
        {
            //------->Function: sin, cos, tan

            //get the number
            if(!numList.Empty())
            {
                input1=numList.Pop()->getInput();
            }
            else
            {
                throw 0;//invalid equation
            }

            if(input1=="x" || input1=="y")
            {
                num1=value;
            }
            else
            {
                num1=atof(input1.c_str());
            }

            //check the type of the function and calculate
            if(token->getInput()=="sin")
            {
                result=sin(num1);
            }
            else if(token->getInput()=="cos")
            {
                result=cos(num1);
            }
            else if(token->getInput()=="tan")
            {
                result=tan(num1);
            }
            else
            {
                input2=numList.Pop()->getInput();
                if(input2=="x" || input2=="y")
                {
                    num2=value;
                }
                else
                {
                    num2=atof(input2.c_str());
                }

                if(token->getInput()=="max")
                {
                    result=max(num1,num2);
                }
                else if(token->getInput()=="min")
                {
                    result=min(num1,num2);
                }
                else if(token->getInput()=="pow")
                {
                    result=pow(num2,num1);
                }
            }

            numList.Push(new Integer(to_string(result)));
        }
    }

    //this is when there is no operator
    if( numList.Top()->getInput()=="x" || numList.Top()->getInput()=="y")
    {
        result=value;
        numList.Push(new Integer(to_string(result)));
    }

    //get the result
    input1=numList.Pop()->getInput();

    if(!numList.Empty())
    {
        throw 0;//invalid equation
    }

    return atof(input1.c_str());
}

