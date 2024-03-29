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

std::vector<std::vector<int>> mapBuilder::getMap() {

    std::vector<std::vector<int>> mep;

    std::string line;
    /*
    std::string line;

    int h = 0;
    while(file >> line) {
        int l = 0;
        mep.resize((h + 1));

        for(int c: line) {
            if(c > -1) {
                mep[h].resize(l + 1, c);
                std::cout << "resize successful" << std::endl;
            }
            h++;
        }
    }*/

    int h = 0;
    while(file) {
        mep.resize(h + 1);

        int l = 0;
        std::getline(file, line);
        std::vector<char> lin(line.begin(), line.end());

        for(char &c: lin) {
            mep[h].resize(l + 1, (c - '0'));
            l++;
        }
        h++;
    }
    return mep;
}

mapBuilder::~mapBuilder()
{
    file.close();
    //dtor
}



