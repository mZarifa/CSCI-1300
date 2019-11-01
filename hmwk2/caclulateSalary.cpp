// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 10

#include <iostream>
#include <math.h>
using namespace std;

// algorithm: to take an inputted number of rainy, cold and sunny days, and calculate the salary of the worker making 10 dollars an hour

int  calculateSalary (int rainyDays, int coldDays, int sunnyDays) //create variables called rainyDays, coldDays, and sunnyDays for input
{
    int effectiveSalary = (rainyDays * 5 + coldDays * 4 + sunnyDays * 8) * 10; //only 5 hours on rainy, 4 on cold, 8 on sunny. Multiply that by dollars per hour (10).
    return effectiveSalary; //output the new value for the salary. 
}
int main() //test cases for this
{
   cout << "the salary for this month is $";
   cout << calculateSalary (1, 3, 4); //test cases with values of 1 rainy day, 3 cold days, 4 sunny days. 
   cout << "\n";
   cout << "the salary for this month is $";
   cout << calculateSalary (11, 4, 20); //test cases with values of 11 rainy day, 3 cold days, 20 sunny days. 
}
