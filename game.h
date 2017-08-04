#ifndef GAME_H
#define GAME_H
#include "constants.h"
#include <SFML/Graphics.hpp>
#include "generatepoints.h"
using namespace std;
class Game
{
public:
    Game();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
private:
    sf::RenderWindow window;

    vector<sf::Vertex> vertices;//plotting points

    sf::RectangleShape yAXIS;
    sf::RectangleShape xAXIS;
    sf::RectangleShape border;

    //the range
    double lowest;
    double highest;

    //the x scales on xAxis
    sf::RectangleShape x_scale_1;
    sf::RectangleShape x_scale_2;
    sf::RectangleShape x_scale_3;
    sf::RectangleShape x_scale_4;
    sf::RectangleShape x_scale_5;
    sf::RectangleShape x_scale_6;
    sf::RectangleShape x_scale_7;
    sf::RectangleShape x_scale_8;

    //the y scales on yAxis
    sf::RectangleShape y_scale_1;
    sf::RectangleShape y_scale_2;
    sf::RectangleShape y_scale_3;
    sf::RectangleShape y_scale_4;
    sf::RectangleShape y_scale_5;
    sf::RectangleShape y_scale_6;
    sf::RectangleShape y_scale_7;
    sf::RectangleShape y_scale_8;

    //font
    sf::Font MyFont;

    //scale numbers
    sf::Text numx1, numx2, numx3, numx4, numx5, numx6, numx7, numx8,
            numy1,numy2,numy3,numy4,numy5,numy6,numy7,numy8, origin ;

    //zoom in zoom out buttons
    sf::RectangleShape zIn;
    sf::RectangleShape zOut;
    sf::Text plusSign;
    sf::Text minusSign;

    //buttons for input:
    sf::RectangleShape integer0;
    sf::Text Tinteger0;

    sf::RectangleShape integer1;
    sf::Text Tinteger1;

    sf::RectangleShape integer2;
    sf::Text Tinteger2;

    sf::RectangleShape integer3;
    sf::Text Tinteger3;

    sf::RectangleShape integer4;
    sf::Text Tinteger4;

    sf::RectangleShape integer5;
    sf::Text Tinteger5;

    sf::RectangleShape integer6;
    sf::Text Tinteger6;

    sf::RectangleShape integer7;
    sf::Text Tinteger7;

    sf::RectangleShape integer8;
    sf::Text Tinteger8;

    sf::RectangleShape integer9;
    sf::Text Tinteger9;

    sf::RectangleShape plus;
    sf::Text Tplus;

    sf::RectangleShape minus;
    sf::Text Tminus;

    sf::RectangleShape multiply;
    sf::Text Tmultiply;

    sf::RectangleShape divide;
    sf::Text Tdivide;

    sf::RectangleShape dot;
    sf::Text Tdot;

    sf::RectangleShape equal;
    sf::Text Tequal;

    sf::RectangleShape leftParen;
    sf::Text TleftParen;

    sf::RectangleShape rightParen;
    sf::Text TrightParen;

    sf::RectangleShape x;
    sf::Text Tx;

    sf::RectangleShape y;
    sf::Text Ty;

    sf::RectangleShape sin;
    sf::Text Tsin;

    sf::RectangleShape cos;
    sf::Text Tcos;

    sf::RectangleShape tan;
    sf::Text Ttan;

    sf::RectangleShape exp;
    sf::Text Texp;

    sf::RectangleShape draw;
    sf::Text Tdraw;

    sf::RectangleShape clear;
    sf::Text Tclear;

    sf::RectangleShape max;
    sf::Text Tmax;

    sf::RectangleShape min;
    sf::Text Tmin;

    sf::RectangleShape pow;
    sf::Text Tpow;

    //the position of the mouse released
    double mouseClickedX;
    double mouseClickedY;


    //filling up the vertices
    void setUpPoints();

    //change the range
    void zoomIn();
    void zoomOut();

    //the equation input
    sf::Text text;
    string input;
    string numberInput;

    //error text
    sf::Text errorMessage;
};

#endif // GAME_H
