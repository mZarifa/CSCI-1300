// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Planet.h"
#include "Planet.cpp"
using namespace std;

int main()
{ //test cases for the Planet class. 
       
    cout << endl;
    cout << "test 1" << endl;
    Planet planet;
    Planet();
    Planet ("Jupiter", 5.33);
    cout << planet.getName() << endl;
    planet.setName("ooga booga");
    cout << planet.getName() << endl;
    cout << planet.getRadius() << endl;
    planet.setRadius(22.333);
    cout << planet.getRadius() << endl;
    cout << planet.getVolume() << endl;
    //should output ooga booga, 0, 22.333, and 46658.4.
    
    cout << endl;
    cout << "test 2" << endl;
    Planet ("Mars", 5.33);
    cout << planet.getName() << endl;
    planet.setName("I want to die");
    cout << planet.getName() << endl;
    cout << planet.getRadius() << endl;
    planet.setRadius(44.333333);
    cout << planet.getRadius() << endl;
    cout << planet.getVolume() << endl;
    //should output ooga booga, then "i want to die", then 22.333, then 44.333, then 364989.
}