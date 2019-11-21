#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"

class tileMap : public sf::Drawable, public sf::Transformable
{
    public:
        tileMap();
        virtual ~tileMap();
        bool load(const std::string&, sf::Vector2u, std::vector<int>, unsigned int, unsigned int);
        bool load(const std::string&, sf::Vector2u, std::vector<std::vector<int>>, unsigned int, unsigned int, sf::Vector2f);
        bool load(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);
    protected:

    private:
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        std::vector<std::vector<char>> pam;
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // TILEMAP_H
