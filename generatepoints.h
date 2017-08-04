#ifndef GENERATEPOINTS_H
#define GENERATEPOINTS_H
#include <iostream>
#include "../../../../Vector_Template/vector.h"
//#include "../../../CS3A Pro Spring16/Map/Map/map.h"
#include "topostfix.h"
#include "tokenizer.h"
using namespace std;

class GeneratePoints
{
public:
    GeneratePoints();

    //takes in the range and increments
    GeneratePoints(double low, double high,double increment);

    //create a vector list of x values and a vector list of y values
    void createList(string input);

    Vector<double> getListX();
    Vector<double> getListY();

    //get the range
    double getLowest();
    double getHighest();

private:
    Vector<double> _x;//list of x values
    Vector<double> _y;//list of y values
    double _increment;
    double _low;
    double _high;
};

#endif // GENERATEPOINTS_H
