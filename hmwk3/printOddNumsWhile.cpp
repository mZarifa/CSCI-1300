// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 8

#include <iostream>
using namespace std;
// algorithm: to print all the odd numbers in a sequence

int printOddNumsWhile (int number) //create a variable called number
{
    int tempvalue = 1; //create a tempvalue and set it to 1
    while (tempvalue <= number) //while the temp value is less than the input number...
    {
        if (tempvalue % 2 == 1) //if the temp value is not divisible by 2
            cout << tempvalue << endl; //output the temp value
            tempvalue ++; // add 2 to the temp value. 
    }
}

int main()
{
    printOddNumsWhile (11);
    printOddNumsWhile (12);
}