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
#include "Player.h"


using namespace std;


#ifndef TEAM_H
#define TEAM_H

class Team
{
    public:
    Team();
    Team(string);
    void setTeamName(string);
    void readRoster(string);
    string getPlayerName(int);
    double getPlayerPoints(int);
    int getNumPlayers();
    string getTeamName();
    
    private:
    string teamName;
    vector <Player> players;
    
};
#endif