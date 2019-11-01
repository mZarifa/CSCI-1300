// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 7

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
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

int readRatings(string fileName, string users[], int ratings [][50], int numUsers, int maxRows, int maxColumns) //create these variables
{
    ifstream in_file; 
    in_file.open(fileName); //open the files
    string line = ""; //create a string called line and make it blank
    int counter = 0; //create a counter and set to 0
    string temparr[51] = ""; //create a temp array with 51 values, instead of 50 (1 for the user and then their 50 ratings)
    if(numUsers == maxRows) //if the number of users is the same as the set max rows
    {
        return -2; //return -2.
    }
    if (in_file.is_open()) //if the file is able to be opened...
    {
        if(numUsers > 0) //if the number of users is greater than 0
        {
            counter = numUsers; //set that to the counter
        }
        while(getline(in_file, line)) //while the file is open, do the following
        {
            if (line.length() != 0) //if the length of the line isnt 0
            {
                split(line, ',', temparr, maxColumns + 1); //run the split function
                users[counter] = temparr[0]; //set the array users in the counter position to the temp array at 0.
                for (int i = 1; i < maxColumns + 1; i++)
                {
                    if(temparr[i] != "") //if the temp array in position i isnt blank
                    {
                        ratings[counter][i - 1] = stoi(temparr[i]); //set the ratings at the position counter, i-1 to the temparray at point i passed as an integer. 
                    }
                }
                counter++; //add 1 to the counter
                
                if(counter == maxRows) //if the counter and maxrows are the same
                {
                    return counter; //output the counter variable
                }
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
    string users[10] = {};
    int ratings[10][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    cout << readRatings("ratings2.txt", users, ratings, numUsers, maxRows, maxColumns) << endl; //should return -1.
    
    
    // -2 for not able to fill arr
    string users2[4] = {"Ninja", "Myth", "Sphyer", "Daequan"};
    int ratings2[4][50] = 
    {
        {1,2,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {2,2,4,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {3,1,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    int numUsers2 = 4;
    int maxRows2 = 4;
    int maxColumns2 = 50;

cout<<readRatings("ratings.txt", users2, ratings2, numUsers2, maxRows2, maxColumns2)<<endl; //should return -2.
}