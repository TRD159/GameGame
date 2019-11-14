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
        //std::cout << "didn't work" << std::endl;
    } else {
        //std::cout << "worked" << std::endl;
    }

    red.setRepeated(true);

    sf::Sprite sprite;
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(800, 600)));
    sprite.setTexture(red);

    sprite.setOrigin(sf::Vector2f(400.f, 300.f));

    sprite.setPosition(400.f, 300.f);

    std::vector<std::vector<char>> pam = m.getMap(6, 8);

    std::vector<std::vector<char>>::iterator row;
    std::vector<char>::iterator col;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        //int h = 0;
        for(row = pam.begin(); row != pam.end(); row++) {
            //int l = 0;
            for(col = row->begin(); col != row->end(); col++) {
                if(*col == '1') {
                    window.draw(sprite);
                    //sprite.rotate(1.f);
                }
            }
        }

        window.display();
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
