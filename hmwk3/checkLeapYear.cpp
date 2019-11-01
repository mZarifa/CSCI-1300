// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 6

#include <iostream>
using namespace std;

//algorithm: checks if a given year is a leapyear

bool checkLeapYear (int year) // delcares the bool type function with the inptted integer as "year"
{
    bool leapYearStatus = false; // set leapyear status to false
    int remainderCentury = year % 100; //create a remainder variable by taking the remainder of the leap year / 100
    if ((year < 1582 && year % 4 == 0 && year > 0 || year > 1582 && year % 400 == 0 && (year - remainderCentury) % 400 == 0 || year > 1582 && year % 4 == 0 ))
    /* this is a long one: so if the year is less than 1582, and its divisible by 4, and its greater than 0, or if the year value is greater than 1582 and is divisible by 400, 
    and the year minus the remainder is also divisible by 4, or if the year is greater than 1582 and divisible by 4, then return true. */
    {
        leapYearStatus = true;
    }
    return leapYearStatus;
}
int main ()
{
    checkLeapYear (1440);
}
