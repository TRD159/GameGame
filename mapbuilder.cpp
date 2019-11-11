#include "mapbuilder.h"
#include <string>
#include <fstream>

mapBuilder::mapBuilder()
{

    //ctor
}

mapBuilder::mapBuilder(std::string nam) {
    name = nam;
    file.open(name);
}

char** mapBuilder::getMap() {
    char** mep = 0;
    mep = new char* [512];

    int h = 511;
    while(file) {
        int w = 0;

        char line[512];
        file.getline(line, 512);

        for(char &c : line) {
            mep[h][w] = c;
            w++;
        }
        h--;
    }

    return mep;
}

mapBuilder::~mapBuilder()
{
    file.close();
    //dtor
}



