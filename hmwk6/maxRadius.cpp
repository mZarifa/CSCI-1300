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
using namespace std;
//function to return the max radius of an inputted planet.


int maxRadius(Planet planetArray[3], int arraySize) //create the function maxRadius using the Planet class. Create the array and an int with the size of it.
{
    int radiusIndex = 0; //set radiusIndex to 0. This will iterate us through the array, and hold the position of the largest Planet.
    double radiusHolder = 0; //set radiusHolder to 0. This will temporarly hold the largest Radius.
    
    if (planetArray[0].getName() == "") //if its blank
    {
        return -1; //return 0.
    }
    
    else
    {
        for (int i = 0; i < arraySize; i++) //if i is less than the size of the array, do the following, then add 1 to i.
        {
            if (planetArray[i].getRadius() > radiusHolder) //if the radius of the planet in planetArray position i is less than the value in radius Holder.
            {
                radiusHolder = planetArray[i].getRadius(); //set the radius holder to that. 
                radiusIndex = i; //set the radiusIndex to that.
            }
        }
        return radiusIndex; //return the largest radius. 
    }
}
