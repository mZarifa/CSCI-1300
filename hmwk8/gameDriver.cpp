// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #8 Problem 4

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "Player.h"
#include "Player.cpp"
#include "Team.h"
#include "Team.cpp"

using namespace std;

string game(Team team1, Team team2)
{
    double team1Points = 0;
    double team2Points = 0;
    
    
    if(team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4) 
    {
        return "forfeit"; //if either team has less than 4 players, return forefit.
    }
    else for (int i = 0; i < 4; i++)
    {
        team1Points = team1Points + team1.getPlayerPoints(i); //add up team1's points
        team2Points = team2Points + team2.getPlayerPoints(i); //add up team2's points.
    }
    
    if(team1Points > team2Points)
    {
        return team1.getTeamName(); //if team1 has more than team 2, team1 wins.
    }
        
    else if(team1Points<team2Points) //if team2 has more than team1, team2 wins.
    {
        return team2.getTeamName();
    }
        
    else if (team1Points == team2Points) //if they're equal
    {
        return "draw"; //return draw
    }
}

int main()
{
    Team team1("Seg Faultline");
    team1.readRoster("roster1.txt");
    Team team2("Team Maim");
    team2.readRoster("roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl; //should output segFaultLine.
}