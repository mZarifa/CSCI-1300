// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #9 Problem 2

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
//algorithm: to take an inputted int and output a string of that int in binary, using recursion and no loop.

string decimalToBinaryRecursive(int input)
{
    string a = ""; //create blank string a
    string b = ""; //create blank string b
    if (input == 0)
    {
        return b + "0"; //if the input is 0, just return 0.
    }

    else
    {
        if(input % 2 == 0) //if the inputted integer is divisible by 2 and has no remainder
        {
            a += "0"; //set the a string to whatever it is, but add 0 to the end
        }
        else
        {
            a += "1"; //else, set the a string to whatever it is, but add 1 to the end.
        }

        return decimalToBinaryRecursive(input / 2) + a; //now do that loop again, but take the inputted number and divide it by 2
        //and then append whatever is in string 'a' to the end of that loop. This continues until the input eventually equals 1.
    }
}


int main()
{ //test cases
    int z = 33;
    string a = decimalToBinaryRecursive(z);
    cout << "Test 1: " << endl;
    cout << "expected: 100001" << endl; 
    cout << "got: " << a << endl;
    cout << endl;

    z = 126;
    a = decimalToBinaryRecursive(z);
    cout << "Test 2: " << endl;
    cout << "expected: 01111110" << endl; 
    cout << "got: " << a << endl;
    cout << endl;
}