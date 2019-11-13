#include <SFML/Graphics.hpp>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <fstream>
#include <string>
#include "mapbuilder.h"

int main()
{
    mapBuilder m("MapData.txt");

    sf::Texture red;

    if(!red.loadFromFile("Tile.png")) {
        std::cout << "didn't work" << std::endl;
    } else {

    }

    std::vector<std::vector<char>> pam = m.getMap(72, 72);

    std::vector<std::vector<char>>::iterator row;
    std::vector<char>::iterator col;

    for(row = pam.begin(); row != pam.end(); row++) {
        for(col = row->begin(); col != row->end(); col++) {
            std::cout << *col << ' ';
        }
        std::cout << std::endl;
    }



    /*for(int y = 0; y < 72; y++) {
        for(int x = 0; x < 72; x++) {
            std::cout << pam[y][x] << " ";
        }
        std::cout << std::endl;
    }*/

    //char** temp = pam;

    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    */

    return 0;
}
