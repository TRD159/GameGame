#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        bool move(int, int);
    protected:

    private:
        sf::Sprite sprite;
        sf::Vector2f position;
};

#endif // PLAYER_H
