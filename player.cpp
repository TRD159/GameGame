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

    //this->setOrigin(siz.x/2.f, siz.y/2.f);

    this->setPosition(pos);

    vertices.setPrimitiveType(sf::Quads);

    //collision = sf::Rect(pos.x, pos.y, siz.x, siz.y);

    //Resize this to however many rects the character sprite will have * 4
    vertices.resize(4);

    //This is their position relative to the origin
    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(siz.x, 0);
    vertices[2].position = sf::Vector2f(siz.x, siz.y);
    vertices[3].position = sf::Vector2f(0, siz.y);

    //This is where they will get their texture
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(siz.x, 0);
    vertices[2].texCoords = sf::Vector2f(siz.x, siz.y);
    vertices[3].texCoords = sf::Vector2f(0, siz.y);

    siiz = siz;

    return true;
}

bool Player::move(float hor, float ver) {
    sf::Vector2f pos = getPosition();

    setPosition(pos.x + hor, pos.y + ver);

    mov(hor, ver);

    return true;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = &spriteSheet;

    target.draw(vertices, states);
}

sf::Vector2f Player::getSiiz() {
    return siiz;
}
