// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #9 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
//algorithm: to take an inputted int and output a string of that int in binary.

string decimalToBinaryIterative(int input)
{
    int length = 0; //create an int to keep track of the length of the string.
    string a = ""; //blank string a 
    string b = ""; //blank string b
    if (input == 0)
    {  
        return "0"; //if its 0, just return 0.
    } 
    else
    {
        for(int i = 0; input > 0; i++) //repeat this until the input is less than 0.
        {
            if(input % 2 == 0) //if the inputted value is divisible by 1
            {
                a += '0'; //set a to whatever is in it plus 0.
            }
            else
            {
                a += '1'; //set a to whatever is in it plus 1.
            }
            length = i; //set the length int to whatever i is
            input = input / 2; //set the input to the input divided by 2
        }
        
    }
    for (int j = length; j >= 0; j--) //reverse the string time. J is the length of string a. While J is greater than or equal to 0, subtract 1 from j, then do this stuff
    {
        b += a[j]; //set string b to whatever is in string a at position j.
    }
    return b;
}


int main()
{
    //test cases
    int z = 33;
    string a = decimalToBinaryIterative(z);
    cout << "Test 1: " << endl;
    cout << "expected: 100001" << endl; 
    cout << "got: " << a << endl;
    cout << endl;
    z = 126;
    a = decimalToBinaryIterative(z);
    cout << "Test 2: " << endl;
    cout << "expected: 01111110" << endl; 
    cout << "got: " << a << endl;
    cout << endl;
}