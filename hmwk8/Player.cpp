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
#include "Player.h"


using namespace std;

Player::Player()
{
    name = "";
    points = 0;
}

Player::Player(string inputName, double value)
{
    name = inputName;
    points = value;
}

string Player::getName()
{
    return name;
}

double Player::getPoints()
{
    return points;
}

void Player::setName(string input)
{
    name = input;
}

void Player::setPoints(double inValue)
{
    points = inValue;
}