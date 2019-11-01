// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #7 Problem 2

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "User.h"
using namespace std;

//algorithm: take the ratings from the users for each book and pass them. 

void split(string line, char deliminator, string words[], int arrSize) //create the variables
{
    
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
}

int readRatings(string fileName, User users[], int numUsers, int userArrSize, int maxColumns) //create these variables
{
    ifstream in_file; 
    in_file.open(fileName); //open the files
    string line = ""; //create a string called line and make it blank
    int counter = numUsers; //create a counter and set to 0
    string temparr[51] = ""; //create a temp array with 51 values, instead of 50 (1 for the user and then their 50 ratings)
    if(numUsers >= userArrSize) //if the number of users is the same as the set max rows or greater than...
    {
        return -2; //return -2.
    }
    if (in_file.is_open()) //if the file is able to be opened...
    {
        if(numUsers > 0) //if the number of users is greater than 0
        {
            counter = numUsers; //set that to the counter
        }
         while(getline(in_file,line) && numUsers < userArrSize)
        {
            if (line.length() != 0) //if the length of the line isnt 0
            {
                split(line, ',', temparr, maxColumns + 1); //run the split function
                users[counter].setUsername(temparr[0]); //set the array users in the counter position to the temp array at 0.
                for (int i = 1; i < maxColumns + 1; i++)
                {
                    if(temparr[i] != "") //if the temp array in position i isnt blank
                    {
                        users[counter].setRatingAt(i - 1, stoi(temparr[i])); //set the ratings at the position counter, i-1 to the temparray at point i passed as an integer. 
                    }
                }
                counter++; //add 1 to the counter
                numUsers++;
            }
        }
        
        in_file.close(); //closes file
        return counter;
    }
    else if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }
}

int main()
{
	
// -2 for not able to fill arr
User users[4];

users[0].setUsername("Ninja");
users[1].setUsername("Myth");
users[2].setUsername("Sphyer");
users[3].setUsername("Daequan");

int numUsers = 4;
int maxRows = 4;
int maxColumns = 50;

cout << readRatings("Ratings.txt", users, numUsers, maxRows, maxColumns)<<endl;
}

