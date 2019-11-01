// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 8

#include <iostream>
#include <math.h>
using namespace std;

// algorithm: to take an inputted value, which is the starting population, and determine the population after one year. 

int population(int startingPopulation) //take the inputted number and created a integer variable 'seconds'
{
  double Birth = 1.0 / 8.0; // 1 birth every 8 seconds. Create a variable for that. 
  double Death = 1.0 / 12;  //1 death every 12 seconds. Create a variable for that. 
  double Immigrant = 1.0 / 27;  //1 immigrant every 27 seconds. Create a variable for that. 
  double changeInPopulation = Birth - Death + Immigrant; //calculate the change in population
  double finalPopulation = startingPopulation + 31536000 * changeInPopulation; //Do the math. 31536000 is the number of seconds in a year.
  // multiply that number by the change in population, which gives the total change in population over that year. Add the initial and final together. 
  return finalPopulation;
}
int main ()//create two test cases
{ //test cases
    cout << population (1000000);
    cout << "\n"; 
    cout << population (10);

}