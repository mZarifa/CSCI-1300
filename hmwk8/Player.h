// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #8 Problem 2

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
    Player(string, double);
    string getName();
    double getPoints();
    void setName(string);
    void setPoints(double);
    
    private:
    string name;
    double points;
    
};

#endif