#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"

class Collidable
{
    public:
        Collidable();
        Collidable(sf::Vector2f, sf::Vector2f);
        virtual ~Collidable();

        bool isIntersecting(Collidable);
        void mov(float, float);

        sf::FloatRect getCol() {
            return collision;
        }
    protected:
        sf::FloatRect collision;

    private:

};

#endif // COLLIDABLE_H
