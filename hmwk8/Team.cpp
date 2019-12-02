// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #8 Problem 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "Team.h"
#include "Player.h"

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
    words[arrayposition] = temp;
}

Team::Team()
{
    teamName = "";
    for(int i = 0; i < players.size(); i++) //create a team, and set their names to blank and players to blank.
    {
        players[i].setName("");
        players[i].setPoints(0);
    }
}

Team::Team(string input)
{
    teamName = input; //set the teamName to input, then...
    for(int i = 0; i < players.size(); i++) 
    {
        players[i].setName(""); //set their names to blank
        players[i].setPoints(0); //set their points to blank
    }
}

void Team::setTeamName(string input)
{
    teamName = input; //function to set input to the teamName.
}

void Team::readRoster(string fileName) //function for reading the roster.
{
    string line = ""; //create a string called line, and make it blank.
    string tempArray[2]; //create a temp array string with size of 3 for the name, players, and the points.
    
    ifstream in_file;
    in_file.open(fileName); //open the file
    
    if(in_file.is_open()) //if its open
    {
        while (getline(in_file, line)) //while its open
        {
            split(line, ',', tempArray, 2); //run the split function
            Player newPlayer; 
            newPlayer.setName(tempArray[0]); //set the new Players to tempArray[0].
            newPlayer.setPoints(stod(tempArray[1])); //set the points to temp
            players.push_back(newPlayer);
        }
        in_file.close(); //close the file.
    }
}

string Team::getPlayerName(int i) //function to get the players names
{
    if (i >= 0 && i < players.size()) //if i is greater than/equal to 0, but less than the fixed player size
    {
        return players[i].getName(); //get the name at the inputted int i
    }
    else
    {
        return "ERROR"; //else return error because they're outside the range of 0 and max players. 
    }
}

double Team::getPlayerPoints(int i) //function to get the points.
{
    if(i >= 0 && i<players.size())  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return players[i].getPoints(); //get the player at array position i's points.
    }
    else
    {
        return -1; //else return -1
    }
}

int Team::getNumPlayers() //function to get the number of players.
{
    return players.size(); //output the size of the team. 
}

string Team::getTeamName() //function to get the team name.
{
    return teamName; //output the team name.
}