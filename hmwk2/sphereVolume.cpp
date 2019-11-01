// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 5

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: take an inputted radius(i) and output a value for volume with test cases to check for funcationality

void sphereVolume(double i) //set the input variable as integer with decimal capability
{
    double volume; //create a variable called 'volume'
    volume = (4.0/3.0) * M_PI * pow(i, 3); //the equation for volume is 4/3 piR^3 where R(radius)= i (the predefined variable)
    cout << "volume: " << volume << endl; //output the valume for volume
}

int main()
{
    sphereVolume (5);
    //tests function with radius of 5
    sphereVolume (10);
    //tests function with radius of 10
}