// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 4

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: take a user inputted radius(radius) and output a value for volume with test cases to check for funcationality. Then output a value for surface area.

int main()
{
    cout << "Enter a radius: " << endl;
    double radius; //create a variable called radius
    cin >> radius; //take user input and set as radius
    double volume; //create a variable called volume
    volume = (4.0/3.0) * M_PI * pow(radius, 3); //the equation for volume. 4/3piR^3. Where R=Radius.
    cout << "volume: " << volume << endl; //output the volume as "Volume: volume"
    
    //the following code is for surface area
    double surface_area; //create a variable for a integer with decimals for surface area.
    surface_area = (4.0) * M_PI * pow(radius, 2); //the equation for surface area. 4piR^2. Take the radius input from the user input.
    cout << "surface area: " << surface_area << endl; //output surface area
}