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
    for(int i = 0; i < players.size(); i++)
    {
        players[i].setName("");
        players[i].setPoints(0);
    }
}

Team::Team(string input)
{
    teamName = input;
    for(int i = 0; i < players.size(); i++)
    {
        players[i].setName("");
        players[i].setPoints(0);
    }
}

void Team::setTeamName(string input)
{
    teamName = input;
}

void Team::readRoster(string fileName)
{
    string line = "";
    string temparr[2];
    
    ifstream in_file;
    in_file.open(fileName);
    
    if(in_file.is_open())
    {
        while (getline(in_file, line))
        {
                    split(line, ',', temparr, 2);
                    
                    Player newPlayer;
                    newPlayer.setName(temparr[0]);
                    newPlayer.setPoints(stod(temparr[1]));
                    players.push_back(newPlayer);
        }
        in_file.close();
    }
}

string Team::getPlayerName(int i)
{
    if (i >= 0 && i < players.size())
    { //ensures that i is within the range of the players vector
        return players[i].getName();
    }
    else
    {
        return "ERROR";
    }
}

double Team::getPlayerPoints(int i)
{
    if(i >= 0 && i<players.size()) //ensures that i is within the range of the players vector
    {
        return players[i].getPoints();
    }
    else
    {
        return -1;
    }
}

int Team::getNumPlayers()
{
    return players.size();
}

string Team::getTeamName()
{
    return teamName;
}