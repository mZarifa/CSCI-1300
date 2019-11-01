// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 6

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: take an inputted radius (i) and output a value for surface area using an equation 4piR^2 with test cases to check for funcationality.

void sphereSurfaceArea (double i) //set the input variable as integer with decimal capability
{ 
    double surfaceArea; //create a variable for a integer with decimals for surface area.
    surfaceArea = (4.0) * M_PI * pow(i, 2); //the equation for surface area. 4piR^2. Take the radius input from the user input.
    cout << "surface area: " << surfaceArea << endl; //output surface area
}

int main()
{
    sphereSurfaceArea (5);
    //tests function with radius of 5
    sphereSurfaceArea (10);
    //tests function with radius of 10
}
