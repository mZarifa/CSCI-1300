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
    string text;
    string trainerName;
    cout << "This is the debugger: Please enter a Pokemon name to check the stats. Type 'Z' to exit " <<
            "type map to output the map." << endl;
    getline(cin, text);
    if (text == "Z" || text == "z")
    {
        return 0;
    }
    if (text == "map")
    {
        Map bigmap;
        bigmap.readMap("mapPoke.txt");
        bigmap.outputMap();
    }
    else
    {
        Player gameTime;
        Pokedex masterDex("Test");
        masterDex.readPokedex("pokemon.txt");
        Pokemon playerPoke1(masterDex.getAllPokeStats(text));
        Pokemon playerPoke2;
        Pokemon playerPoke3;
        Pokemon playerPoke4;
        Pokemon playerPoke5;
        Pokemon playerPoke6;
        cout << "Here's the stats." << endl;
        playerPoke1.getAllStats();
        text = "";
    }
    main();
}


