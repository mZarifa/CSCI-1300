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

using namespace std;


#ifndef POKEMON_H
#define POKEMON_H

class Pokemon
{
    public:
    Pokemon();
    Pokemon(int, string, int, int, int, int, int, string);
    string getName();
    double getValue(string);
    void setValue(string, int);

    private:
    int PokedexNumber;
    string PokemonName;
    int HP;
    int Attack;
    int Defense;
    int Speed;
    int Max;
    string Type;

};

#endif
