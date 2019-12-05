#ifndef COLLIDABLE_H
#define COLLIDABLE_H


class Collidable
{
    public:
        Collidable();
        Collidable(sf::Rect);
        virtual ~Collidable();
        bool isIntersecting(Collidable);
        void mov(float, float);
    protected:

    private:
        sf::Rect collision;
};

#endif // COLLIDABLE_H
