// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 1

#include <iostream>
#include <string>
using namespace std;

//Algorithm: Take a string and count the number of matching characters in the string.

int countMatches (string input, string variable) //create two variables. One called input, and one called variable.
{
    int counter = 0; //create an integer variable called 'counter' and set it to 0.
    
    for (int i = 0; i < input.length(); i++)  //First, create another integer value called i. For i less than the length of the 'input' string, add 1 to i.
    {
        if (input.substr(i, variable.length()) == variable) /*if the substring of characters created from the range from the value of i to the length of the variable string, is equal
                                                             to the words in the string called variable. */
        {
            counter++; // add 1 to the counter
        }
    }
    if (counter == 0) //at the end, if the counter is still 0
    {
        counter = -1; //set the counter to negative 1
    }
    if (variable == "") //if the inputted string variable is blank
    {
        counter = -1; //set the counter to negative 1
    }
    return counter; //end the code by returning the value for the counter.
}

int main()
// test cases
{ 
    string input = "Mississippi"; //test case 1
    string variable = "";
    cout << "test 1: ";
    cout << countMatches(input, variable) << endl; //should return -1
    
    input = "apple";
    variable = "pp";
    cout << "test 2: ";
    cout << countMatches (input, variable) << endl; //should return 1
    
    input = "apple";
    variable = "bb";
    cout << "test 2: ";
    cout << countMatches (input, variable) << endl; //should return -1
}

