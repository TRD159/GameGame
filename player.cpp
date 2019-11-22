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

Player::~Player()
{
    //dtor
}

bool Player::load(const std::string& fileName, int width, int height) {
    if(!spriteSheet.loadFromFile(fileName)) {
        return false;
    }

    for(int x = 0; x < spriteSheet.getSize().x; x += width) {

    }

}
