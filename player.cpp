#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "mapbuilder.h"
#include "tilemap.h"
#include "player.h"

Player::Player()
{
    //ctor
}

Player::Player(std::string name) {
    Player::name = name;
}

Player::~Player()
{
    //dtor
}

bool Player::load(sf::Vector2f pos, sf::Vector2f siz) {
    if(!spriteSheet.loadFromFile(name))
        return false;

    this->setPosition(pos);

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(4);

    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(siz.x, 0);
    vertices[2].position = sf::Vector2f(0, siz.y);
    vertices[3].position = sf::Vector2f(siz.x, siz.y);

    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(siz.x, 0);
    vertices[2].texCoords = sf::Vector2f(0, siz.y);
    vertices[3].texCoords = sf::Vector2f(siz.x, siz.y);

    return true;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = &spriteSheet;

    target.draw(vertices, states);
}
