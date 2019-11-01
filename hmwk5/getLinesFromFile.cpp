// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

//algorithm: to count the number of lines in a file with numbers, and then output those numbers. 

int getLinesFromFile(string fileName ,int arr[], int lengthArray)
{
    string line = "";  //creates a string called 'line' and makes it blank. 
    int arrPos = 0; //creates an int to count the position of the array. 
    
    ifstream in_file; //declares the file input variable
    in_file.open(fileName); //opens the file in in_file
    
    if(in_file.is_open())
    {
        while (getline(in_file,line) && arrPos < lengthArray)
        { //while getline can read a line and the arrayPos is less than the length of the array
            
            if(isdigit (line [0]) && line != "")
            { //if the index is 0, and if the line isn't empty
                arr[arrPos] = stoi(line);  //add that line to the corresponding position in the array
                arrPos++; //add one to the array's position
            }
        }
        in_file.close(); //close the file.
        return arrPos; //return the number of integers in the array.
    }
    else
    {
        return -1; //if the file does not exist, return -1. 
    }
}

int main()
{
    int numArray[4];
    int x = getLinesFromFile("fakefile.txt", numArray, 4); //test case 1. Reading a file that doesn't exist.
    cout << "test 1 returned: " << x << "\n"; //should return -1.
    
    int wordArray[16];
    int y = getLinesFromFile("numbers.txt", wordArray, 16); //test case 2. Reading a file with numbers in it. 
    cout << "test 2 returned: " << y << "\n"; //should return 10.  
    for(int i = 0; i < y; i++)
    {
        cout << wordArray[i] << endl; //should output all the numbers in number.txt
    }
}
