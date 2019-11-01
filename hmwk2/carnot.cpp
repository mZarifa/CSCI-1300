// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 9

#include <iostream>
#include <math.h>
using namespace std;

// algorithm: to take an inputted value, which is the starting population, and determine the population after one year. 

double carnot(double coldTemperature, double hotTemperature)
{
    double carnotEfficency = (1- coldTemperature / hotTemperature);
    return carnotEfficency;
}

int main()
{ //test case for the function, with inputs of 5 for cold, 7 for hot.
    cout << carnot (5, 7);
}