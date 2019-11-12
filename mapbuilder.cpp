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

char** mapBuilder::getMap(int height, int length) {
    char** mep = 0;
    mep = new char* [height];

    int h = 0;
    while(file) {
        mep[h] = new char[length];

        char line[length];
        file.getline(line, length);

        int l = 0;
        for(char &c: line) {
            mep[h][l] = c;
            l++;
        }
        h++;
    }

    /*int h = height - 1;
    while(file) {
        int w = 0;

        char line[width];
        file.getline(line, width);

        for(char &c : line) {
            mep[h][w] = c;
            w++;
        }
        h--;
    }*/

    return mep;
}

mapBuilder::~mapBuilder()
{
    file.close();
    //dtor
}



