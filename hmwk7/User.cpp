// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #7 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "User.h"
using namespace std;


User :: User()
{
    username = ""; // set username to blank string.
    numRatings = 0; //set numratings to 0
    for(int i = 0; i < size; i++) //create a counter i, make it less than the designated size, do the following, then add 1
    {
        ratings[i] = 0; //set ratings at position i to 0. Make the ratings array 0.
    }
}

User :: User(string inputUser, int inputArray[], int inputInt) //initilize user with these variables. A string, array, and an int. 
{
    username = inputUser; //set the input variable username to whatever the string inputUser is.
    if (inputInt <= size) //if the inputInt is less than or equal to size...
    {
        numRatings = inputInt; //set numRatings to the inputInt.
    }
    for(int i = 0; i < size; i++) //create a counter i. While i is less than size, do the following, then add 1
    {
        ratings[i] = 0; //make the ratings array blank again.
    }
    for(int i = 0; i < numRatings; i++) //while the counter i is less than numratings, do the following, then add 1
    {
        ratings[i] = inputArray[i]; //set the ratings array at position i to whatever is in the inputArray at i.
    }
}


string User :: getUsername() //create getUsername function definition
{
    return username; //return the string of username.
}

void User :: setUsername(string inputUser) //create setUsername function with inputUser.
{
    username = inputUser; //set username to inputUser.
}
void User :: setNumRatings (int inputInt) //create setNumRatings function, with inputInt.
{
    numRatings = inputInt; //sets numRatings to inputInt.
}

int User :: getRatingAt(int index) //create getRatingAt function, with an index. 
{
    if(index >= size || index < 0) //if the index is greater than or equal to size, or index is greater than 0. 
    {
        return -1; //return -1.
    }
    else
    {
        return ratings[index]; //else, do that.
    }
}

int User :: getNumRatings() //create getNumRatings function.
{
    return numRatings; //return numRatings value. 
}

bool User :: setRatingAt(int index ,int inputValue) //create boolean of true or false, with setRatingAt with input of index, and inputValue. 
{
    if ((index >= 0 && index < size) && (inputValue >= 0 && inputValue <= 5)) //if index is greater than or equal to 0, and index is less than size, and inputValue is greater than 0, and less than or equal to 5...
    {
        ratings[index] = inputValue; //set ratings at position index to inputValue
        return true; //return true.
    }
    else
    {
        return false;
    }
}

int User :: getSize() //create getSize function.
{
    return size; //return size. 
}