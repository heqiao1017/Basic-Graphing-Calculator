#include "generatepoints.h"

GeneratePoints::GeneratePoints()
{
    _increment=0;
    _low=0;
    _high=0;
}
GeneratePoints::GeneratePoints(double low, double high, double increment)
{
    _increment=increment;
    _low=low;
    _high=high;
}
void GeneratePoints::createList(string input)
{
    Tokenizer tokenizer(input);
    myQueue<Token*> infixList;
    try
    {
        infixList=tokenizer.stokenize();
    }
    catch(int){
        throw 0;
    }
    ToPostfix shuntingyard;
    myQueue<Token*> postfixList=shuntingyard.convert(infixList);

    int type=tokenizer.getValueType();
    cout<<"type: "<<type<<endl;

    cout<<"high: "<<_high<<endl;
    cout<<"low: "<<_low<<endl;
    cout<<"increment: "<<_increment<<endl;
    double range=_high-_low;
    int numOfPoints=range/_increment+1;
    double x=0.0, y=0.0;

    cout<<numOfPoints<<endl;
    //cin.get();

    if(type==0)
    {
        for(int i=0;i<numOfPoints;i++)
        {
            infixList=tokenizer.stokenize();
            postfixList=shuntingyard.convert(infixList);
            x=_low+_increment * i*1.0;

            try{
                y=shuntingyard.Evaluate(postfixList,x);
            }
            catch(int){
                throw 0;
            }

            _x.Add(x);
            _y.Add(y);
        }
    }
    else
    {
        for(int i=0;i<numOfPoints;i++)
        {
            infixList=tokenizer.stokenize();
            postfixList=shuntingyard.convert(infixList);
            y=_low+_increment * i*1.0;

            try{
                x=shuntingyard.Evaluate(postfixList,y);
            }
            catch(int){
                throw 0;
            }
            _x.Add(x);
            _y.Add(y);
        }
    }
//    cout<<"y: "<<_y<<endl;
//    cout<<"x: "<<_x<<endl;
}

Vector<double> GeneratePoints::getListX()
{
    return _x;
}

Vector<double> GeneratePoints::getListY()
{
    return _y;
}

double GeneratePoints::getLowest()
{
    return _low;
}

double GeneratePoints::getHighest()
{
    return _high;
}
