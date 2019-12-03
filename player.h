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
        Player(std::string);
        virtual ~Player();
        bool move(float, float);
        bool load(sf::Vector2f, sf::Vector2f);
    protected:

    private:
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        std::vector<sf::Texture> Textures;
        std::string name;
        sf::Texture spriteSheet;
        sf::VertexArray vertices;


};

#endif // PLAYER_H
