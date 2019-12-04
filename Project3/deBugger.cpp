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
#include "Pokemon.cpp"
#include "Pokedex.h"
#include "Pokedex.cpp"
#include "Player.h"
#include "Player.cpp"
#include "Map.h"
#include "Map.cpp"

using namespace std;

int main()
{
    string trainerName;
    string starterName = "Articuno";
    Player gameTime;
    Pokedex masterDex("Test");
    masterDex.readPokedex("pokemon.txt");
    Pokemon playerPoke1(masterDex.getAllPokeStats(starterName));
    Pokemon playerPoke2;
    Pokemon playerPoke3;
    Pokemon playerPoke4;
    Pokemon playerPoke5;
    Pokemon playerPoke6;
    cout << "Here are your starter Pokemon's Stats!" << endl;
    playerPoke1.getAllStats();
}


