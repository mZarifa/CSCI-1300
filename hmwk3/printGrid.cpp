// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 10

#include <iostream>
using namespace std;
// algorithm: to create a grid for the user based on their input 

void printGrid (int dim1)
{
if (dim1 <=0)
cout << "The grid can only have a positive number of rows and columns." <<endl;
    else
    {
        for (int i = 1; i <= dim1; i++) //create a variable i, and set it to 1. while that number is less than the user input, add 1 to it
        {
        for (int i = 1; i <= dim1; i++) //while that number i is less than 1
        cout << "+--"; // create the starting grid
        cout << "+" << endl; //create the end of the grid
        
        for (int i = 1; i <= dim1; i++)
        cout << "|  "; //create the lines under the grid
        cout << "|" <<endl; //create the final space
        }
        
        for (int i = 1; i <= dim1; i++)
        cout << "+--"; //create the bottom row 
        cout << "+" << endl; // create the + sign
        }
    }
int main()
{
    printGrid (4);
    cout << endl;
    printGrid (5);
    cout << endl;
}