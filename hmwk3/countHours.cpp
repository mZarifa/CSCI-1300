// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 5

#include <iostream>
using namespace std;

// algorithm:

int countHours(int month)
{
    switch (month)
    {
        case 1:
        (month == 1);
        case 3:
        (month == 3);
        case 5:
        (month == 5);
        case 7:
        (month == 7);
        case 8:
        (month == 8);
        case 10:
        (month == 10);
        case 12:
        (month == 12);
        
        (month = 744);
        break;
        // cases for when the number of days in that month is 31
        
        case 2:
        (month == 2);
        month = 672;
        break;
        
        // the only case where the number of days in feburary is 28
        
        case 4:
        (month == 4);
        case 6:
        (month == 6);
        case 9:
        (month == 9);
        case 11:
        (month == 11);
        
        (month = 720);
        break;
        // cases where number of days in the month is 30.
    }
    return month;
}

main () //test cases
{
    countHours (1); // set month to equal 1
    countHours (4); // set month to equal 4
    countHours (12); // set month to equal 12
}