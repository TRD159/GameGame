#include "collidable.h"

Collidable::Collidable()
{
    //ctor
}
Collidable::Collidable(sf::Rect r) {
    collision = r;
}

void Collidable::mov(float x, float y) {
    collision = sf::Rect(collision.left + x, collision.top + y, collision.width, collision.height)
}

bool Collidable::isIntersecting(Collidable c) {
    return collision.intersects(c);
}

Collidable::~Collidable()
{
    delete collision;
    //dtor
}
