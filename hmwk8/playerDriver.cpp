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
#include "Player.cpp"
#include "Team.cpp"

using namespace std;

int main()
{
	Player player("Marcus", 6.2);
	player.setName("Max");
    cout << player.getName() << endl;
    cout << player.getPoints() << endl;
} //override Marcus with Max.