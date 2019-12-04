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

string starterMenu;
int starterMenuInt;
string fileName;
string playerName;
string starterName;

void startUpMenu()
{
    cout << "Enter a name" << endl;
    getline(cin, playerName);
    {
        while (starterMenu != "4")
        {
            cout << "Welcome to the wonderful world of Pokemon " << playerName << "!" << endl;
            cout << "Choose your starter Pokemon!" << endl;
            cout << "1. Bulbasaur" << endl;
            cout << "2. Squirtle" << endl;
            cout << "3. Charmander" << endl;
            cout << "4. Quit" << endl;
            getline(cin, starterMenu);

            if (starterMenu != "1" && starterMenu != "2" && starterMenu != "3" && starterMenu != "4")
            {
                cout << "invalid input! Please enter only the numbers 1, 2, 3, or 4" << endl;
            }
            else
            {
                starterMenuInt = stoi(starterMenu);
                starterMenu = starterMenuInt;
            }

            switch(starterMenuInt)
            {
                case 1:
                {
                    starterName = "Bulbasaur";
                    cout << "You have chosen " << starterName << "!" << " Your adventure begins here!" << endl;
                    return;
                }
                case 2:
                {
                    starterName = "Squirtle";
                    cout << "You have chosen " << starterName << "!" << " Your adventure begins here!" << endl;
                    return;
                }
                case 3:
                {
                    starterName = "Charmander";
                    cout << "You have chosen " << starterName << "!" << " Your adventure begins here!" << endl;
                    return;
                }
                case 4:
                {
                    cout << "Goodbye!" << endl;
                    return;
                }
                default:
                {
                    cout << "Incorrect menu input! Please enter a number!" << endl;
                    break;
                }
            }
        }
    }
}

void mainMenu();
{
    
}

int main()
{
    startUpMenu();
    Player gameTime;
    Pokedex masterDex("Test");
    masterDex.readPokedex("pokemon.txt");
    Pokemon playerPoke1(masterDex.getAllPokeStats(starterName));
    Pokemon playerPoke2;
    Pokemon playerPoke3;
    Pokemon playerPoke4;
    Pokemon playerPoke5;
    Pokemon playerPoke6;
    cout << "Here are your starter Pokemon's stats!" << endl;
    playerPoke1.getAllStats();
    gameTime.setPlayerPokemon(playerPoke1);
}