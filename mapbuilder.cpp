#include "mapbuilder.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

mapBuilder::mapBuilder()
{

    //ctor
}

mapBuilder::mapBuilder(std::string nam) {
    name = nam;
    file.open(name);
}

std::vector<std::vector<char>> mapBuilder::getMap(int height, int length) {

    std::vector<std::vector<char>> mep = std::vector<std::vector<char>>(height, std::vector<char>(length, 0));

    std::string line;

    int h = 0;
    while(file >> line) {
        if(h >= height) {
            break;
        }
        int l = 0;
        for(char &c: line) {
            if(l >= length) {
                break;
            }
            if(c != 0) {
                mep[h][l] = c;
            }
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



