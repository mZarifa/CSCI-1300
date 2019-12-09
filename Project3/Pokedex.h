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
    Pokedex();
    Pokedex(string);
    void readPokedex(string);
    string getPokeName(string);
    int getPokeNumber(string);
    int getPokeHP(string);
    int getPokeAttack(string);
    int getPokeDefense(string);
    int getPokeSpeed(string);
    int getPokeMax(string);
    string getPokeType(string);
    string getPokeType2(string);
    Pokemon getAllPokeStats(string);
    Pokemon getAllPokeStatsByInt(int);

    private:
    string trainerName;
    int PokedexSize = 151;
    vector <Pokemon> pokemons;
    
};
#endif