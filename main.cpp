#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace std;
sf::Vector2f ifs( sf::Vector2f argpos );
sf::Vector2f toscreen( sf::Vector2f argpos );
int main()
{
    srand( time( NULL ) );
    bool cl = true;
    sf::Vector2f pos(0, 0);
    sf::Vector2f finalpos;

    sf::RectangleShape px( sf::Vector2f(1, 1));
    px.setFillColor(sf::Color::White);

    sf::RenderWindow window(sf::VideoMode(700, 700), "My window");
    while (window.isOpen())
    {
        sf::Event event;
        pos = ifs( pos );
        finalpos = toscreen( pos );
        px.setPosition( finalpos );
        //px.setFillColor(sf::Color( (rand() % 2) * 255, (rand() % 2) * 255, (rand() % 2) * 255 ));
        px.setFillColor(sf::Color( 255, 255, 255 ));
        window.draw(px);
        cout << pos.x << ", " << pos.y << " #" << endl;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }

    return 0;
}
sf::Vector2f ifs( sf::Vector2f argpos )
{
    const int ifsn = 4;
    const int ifsc[ 4 ] = { 1, 85, 7, 7 };
    int chance = rand() % 100;
    cout << endl << "XXXX " << chance << " XXXX"  << endl;
    int funcn;
    for( int i = 0; i < ifsn; i++ )
    {
        if( chance - ifsc[ i ] < 0 )
        {
            funcn = i;
            break;
        }
        else
            chance -= ifsc[ i ];
    }
    switch( funcn )
    {
    case 0:
        cout << "$0" << endl;
        return sf::Vector2f( 0.0*argpos.x + 0.0*argpos.y + 0.0, 0.0*argpos.x + 0.16*argpos.y + 0.0 );
    case 1:
        cout << "$1" << endl;
        return sf::Vector2f( 0.85*argpos.x + 0.04*argpos.y + 0.0, -0.04*argpos.x + 0.85*argpos.y + 1.6 );
    case 2:
        cout << "$2" << endl;
        return sf::Vector2f( 0.2*argpos.x - 0.26*argpos.y + 0.0, 0.23*argpos.x + 0.22*argpos.y + 1.6 );
    case 3:
        cout << "$3" << endl;
        return sf::Vector2f( -0.15*argpos.x + 0.28*argpos.y + 0.0, 0.26*argpos.x + 0.24*argpos.y + 0.44 );
    }
}
sf::Vector2f toscreen( sf::Vector2f argpos )
{
    return sf::Vector2f( 200 + 500*argpos.x/8, 50 + 500*argpos.y/8 );
}

////////////////////////////////////////////////////////////////////////////////////
/*sf::Vector2f ifs( sf::Vector2f argpos )
{
    const int ifsn = 3;
    const int ifsc[ 3 ] = { 33, 33, 34 };
    int chance = rand() % 100;
    cout << endl << "XXXX " << chance << " XXXX"  << endl;
    int funcn;
    for( int i = 0; i < ifsn; i++ )
    {
        if( chance - ifsc[ i ] < 0 )
        {
            funcn = i;
            break;
        }
        else
            chance -= ifsc[ i ];
    }
    switch( funcn )
    {
    case 0:
        cout << "$0" << endl;
        return sf::Vector2f( 0.5*argpos.x + 0.0*argpos.y - 0.5, 0.0*argpos.x + 0.5*argpos.y + 0.5 );
    case 1:
        cout << "$1" << endl;
        return sf::Vector2f( 0.5*argpos.x + 0.0*argpos.y - 0.5, 0.0*argpos.x + 0.5*argpos.y - 0.5 );
    case 2:
        cout << "$2" << endl;
        return sf::Vector2f( 0.5*argpos.x + 0.0*argpos.y + 0.5, 0.0*argpos.x + 0.5*argpos.y - 0.5 );
    }
}*/
/*sf::Vector2f toscreen( sf::Vector2f argpos )
{
    return sf::Vector2f( 600 + 500*argpos.x, 600 + 500*argpos.y );
}*/
