// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;
#ifndef PLANET_H
#define PLANET_H

class Planet
{
    public:
    Planet();
    Planet (string, double);
    string getName();
    void setName(string);
    double getRadius();
    void setRadius(double);
    double getVolume();
    
    
    
    private:
    
    string planetName;
    double planetRadius;
}
;
#endif