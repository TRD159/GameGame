#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"
#include "player.h"
#include <thread>

int tileWidth(32);
int tileHeight(32);

float scaleWidth(2.f);
float scaleHeight(2.f);

int main()
{

    mapBuilder m("MapData.txt");

    sf::Texture red;

    if(!red.loadFromFile("Tile.png")) {
        //std::cout << "didn't work" << std::endl;
    } else {
        //std::cout << "worked" << std::endl;
    }

    //red.setRepeated(true);

    std::vector<std::vector<int>> pam = m.getMap();

    for (std::vector<int> c: pam) {
        for(int &u : c) {
            std::cout << u;
        }
        std::cout << std::endl;
    }

    int height = pam.size();
    int length = pam[0].size();

    std::cout << std::endl << height << ", " << length;

    //sf::RenderWindow window(sf::VideoMode(length * tileWidth * scaleWidth, height * tileHeight * scaleHeight), "Game");

    sf::RenderWindow window(sf::VideoMode(400, 400), "Game");

    tileMap map;
    if(!map.load("graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(tileWidth, tileHeight), pam, length, height, sf::Vector2f(scaleWidth, scaleHeight))) {
        return -1;
    }

    sf::View view(sf::FloatRect(0.f, 0.f, 400.f, 400.f));

    view.setCenter(0.f, 0.f);
    view.setViewport(sf::FloatRect(0, 0, 1, 1));

    window.setView(view);

    Player player("Tile.png");
    player.load(sf::Vector2f(0.f, 0.f), sf::Vector2f(32.f, 32.f));

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-0.1f, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(0.1f, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0.f, -0.1f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move(0.f, 0.1f);
        }

        sf::Vector2i pix = window.mapCoordsToPixel(player.getPosition());

        std::cout << pix.x << " " << pix.y << std::endl;

        if(pix.x < 32) {
            view.setCenter(view.getCenter().x - 0.1, view.getCenter().y);
        }
        if(pix.x + player.getSiiz().x > window.getSize().x - 32) {
            view.setCenter(view.getCenter().x + 0.1, view.getCenter().y);
        }

        if(pix.y < 32) {
            view.setCenter(view.getCenter().x, view.getCenter().y - 0.1);
        }
        if(pix.y + player.getSiiz().y > window.getSize().y - 32) {
            view.setCenter(view.getCenter().x, view.getCenter().y + 0.1);
        }

        /*if(pix.x - 384 < window.getSize().x) {
            view.setCenter(sf::Vector2f(view.getCenter().x + 0.1, view.getCenter().y));
        }
        if(pix.x + 384 > 0) {
            view.setCenter(sf::Vector2f(view.getCenter().x - 0.1, view.getCenter().y));
        }*/

        //view.setCenter(player.getPosition().x, player.getPosition().y);
        window.setView(view);

        //std::cout << view.getCenter().x << " " << view.getCenter().y << std::endl;

        window.clear();

        window.draw(map);
        window.draw(player);

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
