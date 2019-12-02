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


#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
    Player();
    Player(string, double, int, string, string);
    string getName();
    double getPoints();
    void setName(string);
    void setPoints(double);
    int getBadges();
    string getPokemon();
    string getInventory();
    void setPokemon(string);
    
    private:
    string name;
    double points;
    int badges;
    string inventory;
    string activePokemon;

};
#endif