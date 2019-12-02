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
#include "Pokemon.h"

using namespace std;


#ifndef POKEDEX_H
#define POKEDEX_H

class Pokedex
{
    public:
    Pokedex(string);
    void readPokemon(string);
    string getPokemon(int);

    private:
    vector <Pokemon> Pokemon;
};

#endif