// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 2

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Planet.h"
#include "maxRadius.cpp"
#include "Planet.cpp"

using namespace std;

int main()

{
    Planet planets[5];
    planets[0] = Planet("On A Cob Planet",1234); 
    planets[1] = Planet("Bird World",4321);
    int idx = maxRadius(planets, 2);
    cout << "test 1: " << endl;
    cout << planets[idx].getName() << endl; //should output bird world
    cout << planets[idx].getRadius() << endl; //should output 4321
    cout << planets[idx].getVolume() << endl; //should output 3.37 e+11
    cout << endl;


	cout << "test 2: " << endl;
    Planet planets2[3];
    planets2[0] = Planet("Parblesnops",44);
    planets2[1] = Planet("Planet Squanch",54);
    planets2[2] = Planet("Delphi 6",54);
    int idx2 = maxRadius(planets2, 3);
    cout << planets2[idx2].getName() << endl; //should output Planet Sasqanch
    cout << planets2[idx2].getRadius() << endl; //should output 54
    cout << planets2[idx2].getVolume() << endl; //should output 659584
}