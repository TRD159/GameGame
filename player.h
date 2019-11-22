#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"
#include "PlayerStates.h"

class Player : public sf::Drawable, public sf::Transformable
{
    public:
        Player();
        virtual ~Player();
        bool move(int, int);
        bool load(const std::string&, int, int);

    protected:

    private:
        std::vector<sf::Texture> Textures;
        sf::Texture spriteSheet;
        sf::Vector2f position;
        sf::VertexArray hitbox;
        sf::VertexArray vertices;

};

#endif // PLAYER_H
