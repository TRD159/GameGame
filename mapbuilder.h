#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <string>
#include <fstream>
#include <vector>


class mapBuilder
{
    public:
        mapBuilder();
        mapBuilder(std::string name);
        virtual ~mapBuilder();
        std::vector<std::vector<int>> getMap();
    protected:
        std::ifstream file;
    private:
        std::string name;

};

#endif // MAPBUILDER_H
