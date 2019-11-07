#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <fstream>

class mapBuilder
{
    public:
        mapBuilder();
        mapBuilder(*string);

    protected:

    private:
        std::ifstream inputter;
};

#endif // MAPBUILDER_H
