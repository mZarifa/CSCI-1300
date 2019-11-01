// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #7 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

#ifndef USER_H
#define USER_H

class User
{
    public:
        User();
        User(string, int ratings[], int);
        string getUsername();
        void setUsername(string);
        int getRatingAt(int);
        bool setRatingAt(int, int);
        int getNumRatings();
        void setNumRatings(int);
        int getSize();
        
    private:
        string username;
        int numRatings;
        const static int size = 50;
        int ratings[size];
}
;
#endif