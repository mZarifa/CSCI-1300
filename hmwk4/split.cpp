 // CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #4 Problem 6
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;
// algorithm: to split a string up based on a certian character. 

int split(string line, char deliminator, string words[], int arrSize) //create the variables
{
    if (line.length() == 0) //if the string is empty
    {
        return 0; //return 0.
    }
    
    string temp = ""; //create a string that is blank.
    int arrayposition = 0; //create a position holder.
    
    for (int i = 0; i < line.length(); i++) //for i less than the length of the line, do the following
    {
        if( line[i] != deliminator) //if the character in the line i isn't the deliminator
        {
            temp = temp + line[i]; //set the temp string to whatever was in it plus that character
        }
        else
        {
            if (i != 0 && i != (line.length() - 1)) // if i isn't 0, and isn't 1 less than the length of the string...
            words[arrayposition] = temp; //set the array of words at the given position to the temp string
            temp = ""; //set the temp string to blank
            arrayposition++; //add 1 to the arrayposition
            
            int check = i + 1; //create a match check, at i + 1
            if (line[check] == deliminator) //if the line at the checker is the deliminator
            {
                i++; //add 1 to i.
            }
            else
            {
                if (i == line.length() - 1) // if i is the same length as the inputted line - 1.
                {
                    i++; //add 1 to i.
                }
            }
        }
    }
    words[arrayposition] = temp; //set the string 'words' to whatever is in temp at the moment. 
    int count = arrayposition + 1; //create an int called count.
    if (count > arrSize) //if the count is greater than the size of the array.
    {
        return -1; //return negative 1
    }
    return count; //return the counter. 
}

int main()
{ //test cases
    string words[6]; //create a string of words max 6.
    cout << split( "one small step", ' ', words, 6) << endl; //split the string "one small step" up by the spaces.
    for (int pos = 0; pos < 6; pos++) //while the variable pos is < 6, add 1 to position
    {
        cout << words[pos] << endl; //output the string at that position, and then make a new line.
    }
    
    words[1]; //create a string of words max 1
    cout << split( "", ' ', words, 0) << endl; //split the string up.
    for (int pos = 0; pos < 0; pos++) //while the variable pos is < 0, add 1 and do the following.
    {
        cout << words[pos] << endl; //output the string at that position, and then make a new line.
    } //should output 0.
}