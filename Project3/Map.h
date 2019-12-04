// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "Player.h"
#include "Pokemon.h"
#include "Pokedex.h"

using namespace std;


#ifndef MAP_H
#define MAP_H

class Map
{
    public:
    Map();
    Map(string);
    void readMap(string);
    void outputMap();

    private:
    vector <string> theMap;

};
#endif