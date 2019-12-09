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
#include "Pokedex.h"

using namespace std;


#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
    Player();
    Player(string, double);
    string getName();
    double getPoints();
    void setName(string);
    void setPoints(double);
    int getBadges();
    string getInventory();
    
    Pokemon setPlayerPokemon(int, Pokemon);
    void addPlayerPokemon(Pokemon);
    Pokemon getPlayerPokemonAt(int);
    void outputAllPlayerPokemon();
    int getPlayerPokemonSize();

    private:
    string name;
    double points;
    int badges;
    string inventory;
    vector <Pokemon> playerPokemon;

};

#endif