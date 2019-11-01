// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 9

#include <iostream>
using namespace std;
// algorithm: to print all the odd numbers in a sequence. 

int printOddNumsFor (int number) //create a variable called number
{
    for (int tempvalue = 1; tempvalue <= number; tempvalue++)
    /*for the new variable tempvalue, if its less than the inputted number, add 
    1 to it */ 
    if (tempvalue % 2 == 1) // if the tempvalue isnt divisible by 2
    {
        cout << tempvalue << endl;//output the temp value
    }
}

int main()
{
    printOddNumsFor(9);
    cout << endl;
    printOddNumsFor(12);
    cout << endl;
}