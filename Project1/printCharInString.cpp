// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 1

#include <iostream>
#include <string>
using namespace std;

//Algorithm: Take a given string and input each character individually on a line.

void printCharInString (string input)
{
    if (input == "") //if the input is just a blank space... 
    {
        cout << "Given string is empty!"; //say that "Given string is empty!"
    }
    else //else
    {
        for (int i = 0; i < input.length(); i++) //create a temp value i, and set it to 0. While i is less than the length of the input, add 1 to i
        {
            cout << input[i] << endl; //then output the letter corresponding to the position (i) in the string. 
        }
    }
}

int main()
// test cases
{   
    //test case 1
    string input = "";
    cout << "test 1: " << endl;
    printCharInString (input);
    cout << endl; //test case should output "Given string is empty!"
    
    //test case 2
    input = "Hello world!";
    cout << "test 2: " << endl;
    printCharInString (input); //should output Hello World! with each character on one line. 
    cout << endl;
    
    //testcase 3
    input = "I hate problem 6 dude.";
    cout << "test 3: " << endl;
    printCharInString (input); //should output I hate problem 6 dude with each character on each line. 
    cout << endl;
}