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


using namespace std;

Player::Player()
{
    name = ""; //global variables of blank name, and default of 0 for points value.
    points = 0;
}

Player::Player(string input, double value)
{
    name = input;
    points = value; 
}

string Player::getName() //function to get the name
{
    return name; //return the name
}

double Player::getPoints() //function to get the points
{
    return points; //return the points
}

void Player::setName(string input) //function to set the name to the inputted string
{
    name = input; //set the name variable to the inputted string.
}

void Player::setPoints(double inValue) //function to set the points to the inputted value (inValue)
{
    points = inValue; //set points to the inputted value. 
}
int Player::getBadges() //function to get the points
{
    return badges; //return the points
}
string Player::getInventory() //function to get all available items
{
    return inventory; //returns all inventory items
}
void Player::setPokemon(string input) //function to set the active Pokemon
{
    activePokemon = input; //sets the active pokemon to the inputted value
}
string Player::getPokemon() //function to get all available items
{
    return activePokemon;
}