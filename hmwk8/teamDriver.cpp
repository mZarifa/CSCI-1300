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
#include "Player.cpp"
#include "Team.cpp"

using namespace std;

int main()
{
	Team team1("Dr.Code");
    cout << team1.getTeamName() << endl;
    team1.readRoster("roster1.txt");
    int n1 = team1.getNumPlayers();
    cout << n1 << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << team1.getPlayerName(i) << " ";
        cout << team1.getPlayerPoints(i) << endl;
    }
    
    Team team2;
    team2.setTeamName("Fault Me Daddy");
    cout << team2.getTeamName() << endl;
    team2.readRoster("roster2.txt");
    int n2 = team2.getNumPlayers();
    cout << n2 << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << team2.getPlayerName(i) << " ";
        cout << team2.getPlayerPoints(i) << endl;
    }

}