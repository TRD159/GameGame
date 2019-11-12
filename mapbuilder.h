#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <string>
#include <fstream>


class mapBuilder
{
    public:
        mapBuilder();
        mapBuilder(std::string name);
        virtual ~mapBuilder();
        char** getMap(int, int);
    protected:
        std::ifstream file;
    private:
        std::string name;

};

#endif // MAPBUILDER_H
