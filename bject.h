#ifndef BJECT_H
#define BJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"
#include "player.h"

class Bject : public Collidable, public sf::Drawable
{
    public:
        Bject();
        Bject(std::string);
        virtual ~Bject();

    protected:

    private:
};

#endif // BJECT_H
