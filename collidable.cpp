#include "collidable.h"

Collidable::Collidable()
{
    collision = sf::FloatRect(0, 0, 0, 0);
    //ctor
}

Collidable::Collidable(sf::Vector2f pos, sf::Vector2f siz) {
    collision = sf::FloatRect(pos.x, pos.y, siz.x, siz.y);
}

void Collidable::mov(float x, float y) {
    collision = sf::FloatRect(collision.left + x, collision.top + y, collision.width, collision.height);
}

bool Collidable::isIntersecting(Collidable c) {
    return collision.intersects(c.getCol());
}

Collidable::~Collidable()
{
    //dtor
}
