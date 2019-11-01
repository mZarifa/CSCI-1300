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
using namespace std;

Planet :: Planet()
{
    planetName = " "; //create planetName, set it to blank.
    planetRadius = 0.0; //create planetRadius, set it to 0. 
}
Planet :: Planet (string n, double r) //create a string called n, and a double called r.
{
    planetName = n; //set planetName to n
    planetRadius = r; //set planetRadius to r.
}
string Planet :: getName() //function for getting the name of the planet.
{
    return planetName; //return the name of the planet. 
}
void Planet :: setName(string s) //function definition to set the name of the planet.
{
    planetName = s; //set the name of the planet to whatever is inputted for s.
}
double Planet :: getRadius() //create the function for getting the radius.
{
    return planetRadius; //return the radius bro.
}
void Planet :: setRadius(double t) //create the function to set the radius.
{
    planetRadius = t; //set the radius to whatever t is.
}
double Planet :: getVolume() //create the fucntion for the volume equation
{
    return (4.0/3.0)* M_PI *pow(planetRadius,3); //thats the volume equation dummy.
}