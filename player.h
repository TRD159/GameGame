#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"
#include "PlayerStates.h"
#include "collidable.h"

class Player: public sf::Drawable, public sf::Transformable, public Collidable {
    public:
        Player();
        Player(std::string);
        virtual ~Player();
        bool move(float, float);
        bool load(sf::Vector2f, sf::Vector2f);
        sf::Vector2f getSiiz();
    protected:

    private:
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
        sf::Vector2f siiz;
        std::vector<sf::Texture> Textures;
        std::string name;
        sf::Texture spriteSheet;
        sf::VertexArray vertices;


};

#endif // PLAYER_H
