#include "game.h"
#include "constants.h"
#include <iostream>
using namespace std;

Game::Game()
{
    //setting up the window
    window.create(sf::VideoMode(SCREEN_WIDTH+500, SCREEN_HEIGHT), "Qiao's Graphing Calculator");
    window.setFramerateLimit(100);

    //setting up the X and Y axis
    yAXIS.setPosition(sf::Vector2f(SCREEN_WIDTH/2,0));
    yAXIS.setSize(sf::Vector2f(1,SCREEN_HEIGHT));

    xAXIS.setPosition(sf::Vector2f(0,SCREEN_HEIGHT/2));
    xAXIS.setSize(sf::Vector2f(SCREEN_WIDTH,1));

    border.setPosition(sf::Vector2f(SCREEN_WIDTH,0));
    border.setSize(sf::Vector2f(1,SCREEN_HEIGHT));

    //setting up the scale on the X and Y axis
    x_scale_1.setPosition(sf::Vector2f(200.0, SCREEN_HEIGHT/2.0-5.0));
    x_scale_1.setSize(sf::Vector2f(2.0,10.0));
    x_scale_2.setPosition(sf::Vector2f(200.0*2, SCREEN_HEIGHT/2.0-5.0));
    x_scale_2.setSize(sf::Vector2f(2.0,10.0));
    x_scale_3.setPosition(sf::Vector2f(200.0*3, SCREEN_HEIGHT/2.0-5.0));
    x_scale_3.setSize(sf::Vector2f(2.0,10.0));
    x_scale_4.setPosition(sf::Vector2f(200.0*4, SCREEN_HEIGHT/2.0-5.0));
    x_scale_4.setSize(sf::Vector2f(2.0,10.0));
    x_scale_5.setPosition(sf::Vector2f(200.0*6, SCREEN_HEIGHT/2.0-5.0));
    x_scale_5.setSize(sf::Vector2f(2.0,10.0));
    x_scale_6.setPosition(sf::Vector2f(200.0*7, SCREEN_HEIGHT/2.0-5.0));
    x_scale_6.setSize(sf::Vector2f(2.0,10.0));
    x_scale_7.setPosition(sf::Vector2f(200.0*8, SCREEN_HEIGHT/2.0-5.0));
    x_scale_7.setSize(sf::Vector2f(2.0,10.0));
    x_scale_8.setPosition(sf::Vector2f(200.0*9, SCREEN_HEIGHT/2.0-5.0));
    x_scale_8.setSize(sf::Vector2f(2.0,10.0));

    y_scale_1.setPosition(sf::Vector2f(1000.0-5.0, 130.0));
    y_scale_1.setSize(sf::Vector2f(10.0,2.0));
    y_scale_2.setPosition(sf::Vector2f(1000.0-5.0, 130.0*2));
    y_scale_2.setSize(sf::Vector2f(10.0,2.0));
    y_scale_3.setPosition(sf::Vector2f(1000.0-5.0, 130.0*3));
    y_scale_3.setSize(sf::Vector2f(10.0,2.0));
    y_scale_4.setPosition(sf::Vector2f(1000.0-5.0, 130.0*4));
    y_scale_4.setSize(sf::Vector2f(10.0,2.0));
    y_scale_5.setPosition(sf::Vector2f(1000.0-5.0, 130.0*6));
    y_scale_5.setSize(sf::Vector2f(10.0,2.0));
    y_scale_6.setPosition(sf::Vector2f(1000.0-5.0, 130.0*7));
    y_scale_6.setSize(sf::Vector2f(10.0,2.0));
    y_scale_7.setPosition(sf::Vector2f(1000.0-5.0, 130.0*8));
    y_scale_7.setSize(sf::Vector2f(10.0,2.0));
    y_scale_8.setPosition(sf::Vector2f(1000.0-5.0, 130.0*9));
    y_scale_8.setSize(sf::Vector2f(10.0,2.0));

    //initialize the range
    lowest=-1000.0;
    highest=1000.0;

    //setting up the scale
    if (!MyFont.loadFromFile("Arial.ttf"))
    {
        cout<<"error"<<endl;
    }
    numx1.setPosition(sf::Vector2f(200.0-15,SCREEN_HEIGHT/2.0+15.0));
    numx1.setFont(MyFont);
    numx1.setString("-"+to_string(highest-200));
    numx1.setCharacterSize(20);
    numx2.setPosition(sf::Vector2f(200.0*2-15,SCREEN_HEIGHT/2.0+15.0));
    numx2.setFont(MyFont);
    numx2.setString("-"+to_string(highest-200*2));
    numx2.setCharacterSize(20);
    numx3.setPosition(sf::Vector2f(200.0*3-15,SCREEN_HEIGHT/2.0+15.0));
    numx3.setFont(MyFont);
    numx3.setString("-"+to_string(highest-200*3));
    numx3.setCharacterSize(20);
    numx4.setPosition(sf::Vector2f(200.0*4-15,SCREEN_HEIGHT/2.0+15.0));
    numx4.setFont(MyFont);
    numx4.setString("-"+to_string(highest-200*4));
    numx4.setCharacterSize(20);
    numx5.setPosition(sf::Vector2f(200.0*6-15,SCREEN_HEIGHT/2.0+15.0));
    numx5.setFont(MyFont);
    numx5.setString(to_string(200*6-highest));
    numx5.setCharacterSize(20);
    numx6.setPosition(sf::Vector2f(200.0*7-15,SCREEN_HEIGHT/2.0+15.0));
    numx6.setFont(MyFont);
    numx6.setString(to_string(200*7-highest));
    numx6.setCharacterSize(20);
    numx7.setPosition(sf::Vector2f(200.0*8-15,SCREEN_HEIGHT/2.0+15.0));
    numx7.setFont(MyFont);
    numx7.setString(to_string(200*8-highest));
    numx7.setCharacterSize(20);
    numx8.setPosition(sf::Vector2f(200.0*9-15,SCREEN_HEIGHT/2.0+15.0));
    numx8.setFont(MyFont);
    numx8.setString(to_string(200.0*9-highest));
    numx8.setCharacterSize(20);

    numy1.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130-15.0));
    numy1.setFont(MyFont);
    numy1.setString(to_string(130.0*4));
    numy1.setCharacterSize(20);
    numy2.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*2-15.0));
    numy2.setFont(MyFont);
    numy2.setString(to_string(130.0*3));
    numy2.setCharacterSize(20);
    numy3.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*3-15.0));
    numy3.setFont(MyFont);
    numy3.setString(to_string(130.0*2));
    numy3.setCharacterSize(20);
    numy4.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*4-15.0));
    numy4.setFont(MyFont);
    numy4.setString(to_string(130.0));
    numy4.setCharacterSize(20);
    numy5.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*6-15.0));
    numy5.setFont(MyFont);
    numy5.setString("-"+to_string(130.0));
    numy5.setCharacterSize(20);
    numy6.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*7-15.0));
    numy6.setFont(MyFont);
    numy6.setString("-"+to_string(130.0*2));
    numy6.setCharacterSize(20);
    numy7.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*8-15.0));
    numy7.setFont(MyFont);
    numy7.setString("-"+to_string(130.0*3));
    numy7.setCharacterSize(20);
    numy8.setPosition(sf::Vector2f(SCREEN_WIDTH/2+15.0, 130*9-15.0));
    numy8.setFont(MyFont);
    numy8.setString("-"+to_string(130.0*4));
    numy8.setCharacterSize(20);

    //setting up zoom in and out buttons
    zIn.setSize(sf::Vector2f(50,50));
    zIn.setPosition(sf::Vector2f(1900,100));
    zOut.setSize(sf::Vector2f(50,50));
    zOut.setPosition(sf::Vector2f(1900,155));
    plusSign.setFont(MyFont);
    plusSign.setString("+");
    plusSign.setPosition(sf::Vector2f(1915,103));
    plusSign.setCharacterSize(40);
    plusSign.setColor(sf::Color::Black);
    minusSign.setFont(MyFont);
    minusSign.setString("-");
    minusSign.setPosition(sf::Vector2f(1918,145));
    minusSign.setCharacterSize(50);
    minusSign.setColor(sf::Color::Black);


    //setting up panel buttons for input equation
    integer0.setSize(sf::Vector2f(50,50));
    integer0.setPosition(sf::Vector2f(2150,500));
    Tinteger0.setFont(MyFont);
    Tinteger0.setColor(sf::Color::Black);
    Tinteger0.setString("0");
    Tinteger0.setCharacterSize(40);
    Tinteger0.setPosition(sf::Vector2f(2165, 503));

    integer1.setSize(sf::Vector2f(50,50));
    integer1.setPosition(sf::Vector2f(2205,500));
    Tinteger1.setFont(MyFont);
    Tinteger1.setColor(sf::Color::Black);
    Tinteger1.setString("1");
    Tinteger1.setCharacterSize(40);
    Tinteger1.setPosition(sf::Vector2f(2220, 503));


    integer2.setSize(sf::Vector2f(50,50));
    integer2.setPosition(sf::Vector2f(2260,500));
    Tinteger2.setFont(MyFont);
    Tinteger2.setColor(sf::Color::Black);
    Tinteger2.setString("2");
    Tinteger2.setCharacterSize(40);
    Tinteger2.setPosition(sf::Vector2f(2275, 503));


    integer3.setSize(sf::Vector2f(50,50));
    integer3.setPosition(sf::Vector2f(2315,500));
    Tinteger3.setFont(MyFont);
    Tinteger3.setColor(sf::Color::Black);
    Tinteger3.setString("3");
    Tinteger3.setCharacterSize(40);
    Tinteger3.setPosition(sf::Vector2f(2330, 503));


    integer4.setSize(sf::Vector2f(50,50));
    integer4.setPosition(sf::Vector2f(2150,555));
    Tinteger4.setFont(MyFont);
    Tinteger4.setColor(sf::Color::Black);
    Tinteger4.setString("4");
    Tinteger4.setCharacterSize(40);
    Tinteger4.setPosition(sf::Vector2f(2165, 558));


    integer5.setSize(sf::Vector2f(50,50));
    integer5.setPosition(sf::Vector2f(2205,555));
    Tinteger5.setFont(MyFont);
    Tinteger5.setColor(sf::Color::Black);
    Tinteger5.setString("5");
    Tinteger5.setCharacterSize(40);
    Tinteger5.setPosition(sf::Vector2f(2220, 558));


    integer6.setSize(sf::Vector2f(50,50));
    integer6.setPosition(sf::Vector2f(2260,555));
    Tinteger6.setFont(MyFont);
    Tinteger6.setColor(sf::Color::Black);
    Tinteger6.setString("6");
    Tinteger6.setCharacterSize(40);
    Tinteger6.setPosition(sf::Vector2f(2275, 558));


    integer7.setSize(sf::Vector2f(50,50));
    integer7.setPosition(sf::Vector2f(2315,555));
    Tinteger7.setFont(MyFont);
    Tinteger7.setColor(sf::Color::Black);
    Tinteger7.setString("7");
    Tinteger7.setCharacterSize(40);
    Tinteger7.setPosition(sf::Vector2f(2330, 558));


    integer8.setSize(sf::Vector2f(50,50));
    integer8.setPosition(sf::Vector2f(2150,610));
    Tinteger8.setFont(MyFont);
    Tinteger8.setColor(sf::Color::Black);
    Tinteger8.setString("8");
    Tinteger8.setCharacterSize(40);
    Tinteger8.setPosition(sf::Vector2f(2165, 613));


    integer9.setSize(sf::Vector2f(50,50));
    integer9.setPosition(sf::Vector2f(2205,610));
    Tinteger9.setFont(MyFont);
    Tinteger9.setColor(sf::Color::Black);
    Tinteger9.setString("9");
    Tinteger9.setCharacterSize(40);
    Tinteger9.setPosition(sf::Vector2f(2220, 613));


    plus.setSize(sf::Vector2f(50,50));
    plus.setPosition(sf::Vector2f(2260,610));
    Tplus.setFont(MyFont);
    Tplus.setColor(sf::Color::Black);
    Tplus.setString("+");
    Tplus.setCharacterSize(40);
    Tplus.setPosition(sf::Vector2f(2275, 613));


    minus.setSize(sf::Vector2f(50,50));
    minus.setPosition(sf::Vector2f(2315,610));
    Tminus.setFont(MyFont);
    Tminus.setColor(sf::Color::Black);
    Tminus.setString("-");
    Tminus.setCharacterSize(40);
    Tminus.setPosition(sf::Vector2f(2330, 613));

    multiply.setSize(sf::Vector2f(50,50));
    multiply.setPosition(sf::Vector2f(2150,665));
    Tmultiply.setFont(MyFont);
    Tmultiply.setColor(sf::Color::Black);
    Tmultiply.setString("*");
    Tmultiply.setCharacterSize(40);
    Tmultiply.setPosition(sf::Vector2f(2165, 668));


    divide.setSize(sf::Vector2f(50,50));
    divide.setPosition(sf::Vector2f(2205,665));
    Tdivide.setFont(MyFont);
    Tdivide.setColor(sf::Color::Black);
    Tdivide.setString("/");
    Tdivide.setCharacterSize(40);
    Tdivide.setPosition(sf::Vector2f(2220, 668));


    dot.setSize(sf::Vector2f(50,50));
    dot.setPosition(sf::Vector2f(2260,665));
    Tdot.setFont(MyFont);
    Tdot.setColor(sf::Color::Black);
    Tdot.setString(".");
    Tdot.setCharacterSize(40);
    Tdot.setPosition(sf::Vector2f(2275, 660));


    equal.setSize(sf::Vector2f(50,50));
    equal.setPosition(sf::Vector2f(2315,665));
    Tequal.setFont(MyFont);
    Tequal.setColor(sf::Color::Black);
    Tequal.setString("=");
    Tequal.setCharacterSize(40);
    Tequal.setPosition(sf::Vector2f(2330, 668));


    leftParen.setSize(sf::Vector2f(50,50));
    leftParen.setPosition(sf::Vector2f(2150,720));
    TleftParen.setFont(MyFont);
    TleftParen.setColor(sf::Color::Black);
    TleftParen.setString("(");
    TleftParen.setCharacterSize(40);
    TleftParen.setPosition(sf::Vector2f(2165, 723));


    rightParen.setSize(sf::Vector2f(50,50));
    rightParen.setPosition(sf::Vector2f(2205,720));
    TrightParen.setFont(MyFont);
    TrightParen.setColor(sf::Color::Black);
    TrightParen.setString(")");
    TrightParen.setCharacterSize(40);
    TrightParen.setPosition(sf::Vector2f(2220, 723));


    x.setSize(sf::Vector2f(50,50));
    x.setPosition(sf::Vector2f(2260,720));
    Tx.setFont(MyFont);
    Tx.setColor(sf::Color::Black);
    Tx.setString("x");
    Tx.setCharacterSize(40);
    Tx.setPosition(sf::Vector2f(2275, 723));


    y.setSize(sf::Vector2f(50,50));
    y.setPosition(sf::Vector2f(2315,720));
    Ty.setFont(MyFont);
    Ty.setColor(sf::Color::Black);
    Ty.setString("y");
    Ty.setCharacterSize(40);
    Ty.setPosition(sf::Vector2f(2330, 723));


    sin.setSize(sf::Vector2f(50,50));
    sin.setPosition(sf::Vector2f(2150,775));
    Tsin.setFont(MyFont);
    Tsin.setColor(sf::Color::Black);
    Tsin.setString("sin");
    Tsin.setCharacterSize(30);
    Tsin.setPosition(sf::Vector2f(2155, 778));


    cos.setSize(sf::Vector2f(50,50));
    cos.setPosition(sf::Vector2f(2205,775));
    Tcos.setFont(MyFont);
    Tcos.setColor(sf::Color::Black);
    Tcos.setString("cos");
    Tcos.setCharacterSize(30);
    Tcos.setPosition(sf::Vector2f(2208, 778));


    tan.setSize(sf::Vector2f(50,50));
    tan.setPosition(sf::Vector2f(2260,775));
    Ttan.setFont(MyFont);
    Ttan.setColor(sf::Color::Black);
    Ttan.setString("tan");
    Ttan.setCharacterSize(30);
    Ttan.setPosition(sf::Vector2f(2265, 778));


    exp.setSize(sf::Vector2f(50,50));
    exp.setPosition(sf::Vector2f(2315,775));
    Texp.setFont(MyFont);
    Texp.setColor(sf::Color::Black);
    Texp.setString("^");
    Texp.setCharacterSize(40);
    Texp.setPosition(sf::Vector2f(2330, 778));


    draw.setSize(sf::Vector2f(80,50));
    draw.setPosition(sf::Vector2f(2150,830));
    Tdraw.setFont(MyFont);
    Tdraw.setColor(sf::Color::Black);
    Tdraw.setString("Draw");
    Tdraw.setCharacterSize(30);
    Tdraw.setPosition(sf::Vector2f(2155, 833));


    clear.setSize(sf::Vector2f(80,50));
    clear.setPosition(sf::Vector2f(2235,830));
    Tclear.setFont(MyFont);
    Tclear.setColor(sf::Color::Black);
    Tclear.setString("Clear");
    Tclear.setCharacterSize(30);
    Tclear.setPosition(sf::Vector2f(2240, 833));

    max.setSize(sf::Vector2f(80,50));
    max.setPosition(sf::Vector2f(2150,885));
    Tmax.setFont(MyFont);
    Tmax.setColor(sf::Color::Black);
    Tmax.setString("max");
    Tmax.setCharacterSize(30);
    Tmax.setPosition(sf::Vector2f(2155, 888));

    min.setSize(sf::Vector2f(80,50));
    min.setPosition(sf::Vector2f(2235,885));
    Tmin.setFont(MyFont);
    Tmin.setColor(sf::Color::Black);
    Tmin.setString("min");
    Tmin.setCharacterSize(30);
    Tmin.setPosition(sf::Vector2f(2240, 888));

    pow.setSize(sf::Vector2f(80,50));
    pow.setPosition(sf::Vector2f(2320,885));
    Tpow.setFont(MyFont);
    Tpow.setColor(sf::Color::Black);
    Tpow.setString("pow");
    Tpow.setCharacterSize(30);
    Tpow.setPosition(sf::Vector2f(2325, 888));

//**********************************************************************************

    //setting up the input field
    text.setFont(MyFont);
    text.setPosition(sf::Vector2f(2050,300));
    text.setCharacterSize(20);
    input="";
    numberInput="";

    //setting up the error message showing
    errorMessage.setFont(MyFont);
    errorMessage.setPosition(sf::Vector2f(2050,350));
    errorMessage.setCharacterSize(20);
}

void Game::setUpPoints()
{
//    cout<<"input: "<<input<<endl;
//    cout<<"lowest: "<<lowest<<endl;
//    cout<<"highest: "<<highest<<endl;
//    string input1="x = sin y END";//standard format
//    input="y = tan ( 17 * x ) + 1 / tan ( 17 * x ) END";
//    input="y = sin ( sin ( sin ( 1 / x * 1 / x ) ) ) END";
//    GeneratePoints map(lowest,highest,0.1*(highest/1000.0));

    GeneratePoints map(lowest,highest,0.5*(highest/1000.0));

    //every time redraw, clear the vertices array
    if(!vertices.empty())
    {
        vertices.clear();
    }

    //if there is input equation, fill up the vertices array
    if(input!="")
    {
        try{
            map.createList(input);
        }
        catch(int)
        {
            throw 0;
        }
        Vector<double> _X;
        Vector<double> _Y;
        _X=map.getListX();//the array of x values
        _Y=map.getListY();//the array of y values
//        cout<<"x: "<<_X;
//        cout<<"y: "<<_Y;
        if(highest!=0)
        {
            double conversionX=1000.0/(highest*1.0);
            double conversionY=650.0/(highest*1.0*650/1000.0);
            double value,result;
            for(int i=0;i<_X.getSize();i++)
            {
                value=_X[i]*conversionX+ SCREEN_WIDTH/2;
                result=SCREEN_HEIGHT/2-_Y[i]*conversionY;

                //only push the pixel points that are inside the drawing screen
                if( (value>0 && value<2000) && (result>0 && result<1300))
                {
                    vertices.push_back(sf::Vertex(sf::Vector2f(value,result), sf::Color::Green));
                }
            }
        }
    }
}

void Game::Draw()
{
    window.draw(text);
    window.draw(errorMessage);

    window.draw(yAXIS);
    window.draw(xAXIS);
    window.draw(border);

    window.draw(x_scale_1);
    window.draw(x_scale_2);
    window.draw(x_scale_3);
    window.draw(x_scale_4);
    window.draw(x_scale_5);
    window.draw(x_scale_6);
    window.draw(x_scale_7);
    window.draw(x_scale_8);

    window.draw(y_scale_1);
    window.draw(y_scale_2);
    window.draw(y_scale_3);
    window.draw(y_scale_4);
    window.draw(y_scale_5);
    window.draw(y_scale_6);
    window.draw(y_scale_7);
    window.draw(y_scale_8);


    window.draw(numx1);
    window.draw(numx2);
    window.draw(numx3);
    window.draw(numx4);
    window.draw(numx5);
    window.draw(numx6);
    window.draw(numx7);
    window.draw(numx8);

    window.draw(numy1);
    window.draw(numy2);
    window.draw(numy3);
    window.draw(numy4);
    window.draw(numy5);
    window.draw(numy6);
    window.draw(numy7);
    window.draw(numy8);

    window.draw(zIn);
    window.draw(zOut);
    window.draw(plusSign);
    window.draw(minusSign);

    window.draw(integer0);
    window.draw(Tinteger0);

    window.draw(integer1);
    window.draw(Tinteger1);

    window.draw(integer2);
    window.draw(Tinteger2);

    window.draw(integer3);
    window.draw(Tinteger3);

    window.draw(integer4);
    window.draw(Tinteger4);

    window.draw(integer5);
    window.draw(Tinteger5);

    window.draw(integer6);
    window.draw(Tinteger6);

    window.draw(integer7);
    window.draw(Tinteger7);

    window.draw(integer8);
    window.draw(Tinteger8);

    window.draw(integer9);
    window.draw(Tinteger9);

    window.draw(plus);
    window.draw(Tplus);

    window.draw(minus);
    window.draw(Tminus);

    window.draw(multiply);
    window.draw(Tmultiply);

    window.draw(divide);
    window.draw(Tdivide);

    window.draw(dot);
    window.draw(Tdot);

    window.draw(equal);
    window.draw(Tequal);

    window.draw(leftParen);
    window.draw(TleftParen);

    window.draw(rightParen);
    window.draw(TrightParen);

    window.draw(x);
    window.draw(Tx);

    window.draw(y);
    window.draw(Ty);

    window.draw(sin);
    window.draw(Tsin);

    window.draw(cos);
    window.draw(Tcos);

    window.draw(tan);
    window.draw(Ttan);

    window.draw(exp);
    window.draw(Texp);

    window.draw(max);
    window.draw(Tmax);

    window.draw(min);
    window.draw(Tmin);

    window.draw(draw);
    window.draw(Tdraw);

    window.draw(clear);
    window.draw(Tclear);

    window.draw(pow);
    window.draw(Tpow);


    window.draw(&vertices[0],vertices.size(),sf::Points);
}

void Game::update()
{
    //setUpPoints();
}

void Game::render()
{
    window.clear();
    Draw();
    window.display();
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left )
                {
                    mouseClickedX=event.mouseButton.x;
                    mouseClickedY=event.mouseButton.y;

                    if((mouseClickedX>1900.0 && mouseClickedX<1950.0) && (mouseClickedY>100 && mouseClickedY<150))
                    {
                        //zoom in button clicked
                        zoomIn();
                        setUpPoints();
                    }
                    else if((mouseClickedX>1900.0 && mouseClickedX<1950.0)&& (mouseClickedY>155 && mouseClickedY<205))
                    {
                        //zoom out button clicked
                        zoomOut();
                        setUpPoints();
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>500 && mouseClickedY<550))
                    {
                        //press 0
                        numberInput.append("0");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2205.0 && mouseClickedX<2255.0)&& (mouseClickedY>500 && mouseClickedY<550))
                    {
                        //press 1
                        numberInput.append("1");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2260.0 && mouseClickedX<2310.0)&& (mouseClickedY>500 && mouseClickedY<550))
                    {
                        //2
                        numberInput.append("2");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2315.0 && mouseClickedX<2365.0)&& (mouseClickedY>500 && mouseClickedY<550))
                    {
                        //3
                        numberInput.append("3");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>555 && mouseClickedY<605))
                    {
                        //4
                        numberInput.append("4");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2205.0 && mouseClickedX<2255.0)&& (mouseClickedY>555 && mouseClickedY<605))
                    {
                        //5
                        numberInput.append("5");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2260.0 && mouseClickedX<2310.0)&& (mouseClickedY>555 && mouseClickedY<605))
                    {
                        //6
                        numberInput.append("6");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2315.0 && mouseClickedX<2365.0)&& (mouseClickedY>555 && mouseClickedY<605))
                    {
                        //7
                        numberInput.append("7");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>610 && mouseClickedY<660))
                    {
                        //8
                        numberInput.append("8");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2205.0 && mouseClickedX<2255.0)&& (mouseClickedY>610 && mouseClickedY<660))
                    {
                        //9
                        numberInput.append("9");
                        text.setString(input+numberInput);
                    }
                    else if((mouseClickedX>2260.0 && mouseClickedX<2310.0)&& (mouseClickedY>610 && mouseClickedY<660))
                    {
                        //+
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("+ ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2315.0 && mouseClickedX<2365.0)&& (mouseClickedY>610 && mouseClickedY<660))
                    {
                        //-
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("-");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>665 && mouseClickedY<715))
                    {
                        //*
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("* ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2205.0 && mouseClickedX<2255.0)&& (mouseClickedY>665 && mouseClickedY<715))
                    {
                        //
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("/ ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2260.0 && mouseClickedX<2310.0)&& (mouseClickedY>665 && mouseClickedY<715))
                    {
                        //.
                        numberInput.append(".");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2315.0 && mouseClickedX<2365.0)&& (mouseClickedY>665 && mouseClickedY<715))
                    {
                        //=
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("= ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>720 && mouseClickedY<770))
                    {
                        //(
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("( ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2205.0 && mouseClickedX<2255.0)&& (mouseClickedY>720 && mouseClickedY<770))
                    {
                        //)
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append(") ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2260.0 && mouseClickedX<2310.0)&& (mouseClickedY>720 && mouseClickedY<770))
                    {
                        //x
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("x ");
                        text.setString(input);

                    }
                    else if((mouseClickedX>2315.0 && mouseClickedX<2365.0)&& (mouseClickedY>720 && mouseClickedY<770))
                    {
                        //y
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("y ");
                        text.setString(input);

                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>775 && mouseClickedY<825))
                    {
                        //sin
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("sin ");
                        text.setString(input);

                    }
                    else if((mouseClickedX>2205.0 && mouseClickedX<2255.0)&& (mouseClickedY>775 && mouseClickedY<825))
                    {
                        //cos
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("cos ");
                        text.setString(input);

                    }
                    else if((mouseClickedX>2260.0 && mouseClickedX<2310.0)&& (mouseClickedY>775 && mouseClickedY<825))
                    {
                        //tan
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("tan ");
                        text.setString(input);

                    }
                    else if((mouseClickedX>2315.0 && mouseClickedX<2365.0)&& (mouseClickedY>775 && mouseClickedY<825))
                    {
                        //exp
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("^ ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2200.0)&& (mouseClickedY>830 && mouseClickedY<880))
                    {
                        //draw
                        if(numberInput!="")
                        {
                            input.append(numberInput);
                            input.append(" ");
                            numberInput="";
                        }
                        input.append("END");

                        text.setString(input);

                        //checking errors
                        try{
                            setUpPoints();
                        }
                        catch(int)
                        {
                            errorMessage.setString("Invalid equation and standard form is x= or y= ");
                        }
                    }
                    else if((mouseClickedX>2235.0 && mouseClickedX<2285.0)&& (mouseClickedY>830 && mouseClickedY<880))
                    {
                        //clear
                        input="";
                        text.setString(input);
                        errorMessage.setString("");
                        vertices.clear();

                        //reset the range and scales
                        lowest=-1000.0;
                        highest=1000.0;
                        numx1.setString("-"+to_string(highest-200));
                        numx2.setString("-"+to_string(highest-200*2));
                        numx3.setString("-"+to_string(highest-200*3));
                        numx4.setString("-"+to_string(highest-200*4));
                        numx5.setString(to_string(200*6-highest));
                        numx6.setString(to_string(200*7-highest));
                        numx7.setString(to_string(200*8-highest));
                        numx8.setString(to_string(200.0*9-highest));
                        numy1.setString(to_string(130.0*4));
                        numy2.setString(to_string(130.0*3));
                        numy3.setString(to_string(130.0*2));
                        numy4.setString(to_string(130.0));
                        numy5.setString("-"+to_string(130.0));
                        numy6.setString("-"+to_string(130.0*2));
                        numy7.setString("-"+to_string(130.0*3));
                        numy8.setString("-"+to_string(130.0*4));
                    }
                    else if((mouseClickedX>2150.0 && mouseClickedX<2230.0)&& (mouseClickedY>885 && mouseClickedY<935))
                    {
                        //max
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("max ");
                        text.setString(input);

                    }
                    else if((mouseClickedX>2235.0 && mouseClickedX<2315.0)&& (mouseClickedY>885 && mouseClickedY<935))
                    {
                        //min
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("min ");
                        text.setString(input);
                    }
                    else if((mouseClickedX>2320.0 && mouseClickedX<2400.0)&& (mouseClickedY>885 && mouseClickedY<935))
                    {
                        //pow
                        if(input[input.length()-1]=='-')
                        {
                            input.append(" ");
                        }
                        input.append("pow ");
                        text.setString(input);
                    }
                    break;
                }
            default:
                break;
           }
        }
    }
void Game::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
}

void Game::zoomIn()
{
    lowest/=2;
    highest/=2;

    string holdStr= numx1.getString();
    numx1.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx2.getString();
    numx2.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx3.getString();
    numx3.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx4.getString();
    numx4.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx5.getString();
    numx5.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx6.getString();
    numx6.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx7.getString();
    numx7.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numx8.getString();
    numx8.setString(to_string(atof(holdStr.c_str())/2.0));

    holdStr=numy1.getString();
    numy1.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy2.getString();
    numy2.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy3.getString();
    numy3.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy4.getString();
    numy4.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy5.getString();
    numy5.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy6.getString();
    numy6.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy7.getString();
    numy7.setString(to_string(atof(holdStr.c_str())/2.0));
    holdStr=numy8.getString();
    numy8.setString(to_string(atof(holdStr.c_str())/2.0));


}

void Game::zoomOut()
{
    lowest*=2;
    highest*=2;

    string holdStr= numx1.getString();
    numx1.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx2.getString();
    numx2.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx3.getString();
    numx3.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx4.getString();
    numx4.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx5.getString();
    numx5.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx6.getString();
    numx6.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx7.getString();
    numx7.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numx8.getString();
    numx8.setString(to_string(atof(holdStr.c_str())*2.0));

    holdStr=numy1.getString();
    numy1.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy2.getString();
    numy2.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy3.getString();
    numy3.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy4.getString();
    numy4.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy5.getString();
    numy5.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy6.getString();
    numy6.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy7.getString();
    numy7.setString(to_string(atof(holdStr.c_str())*2.0));
    holdStr=numy8.getString();
    numy8.setString(to_string(atof(holdStr.c_str())*2.0));
}

