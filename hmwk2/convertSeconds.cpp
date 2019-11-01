// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 7

#include <iostream>
#include <math.h>
using namespace std;

// algorithm: to convert an inputted number of seconds to break up into hours, minutes, and seconds.

void convertSeconds (int seconds) /take the inputted number and created a integer variable 'seconds'
{
    int hours, minutes; //create two variables, hours and minutes to set as integers
    minutes = seconds / 60; // set the variable minutes, and assign that minutes is the inputted seconds / 60
    hours = minutes / 60; //set the variable hours, and assign that hours is the newly created variable seconds / 60
    cout << int(hours) << " hour(s) " << int(minutes%60) << " minute(s) " << int(seconds%60) << " second(s)"; /* Output and do the math. Take the remainder of seconds / 60, output it. Then take 
                                                                                                                 the remainder of minutes / 60, and output it. Then take the value for hours and 
                                                                                                                 output it. */
}

int main()
{
    //test cases for the algorithm.
    convertSeconds (10); //test value of 10 seconds
    convertSeconds(3600); //test value of 36000 seconds

}