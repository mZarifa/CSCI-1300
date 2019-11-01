// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 2 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H


class Library
{
    public:
        Library();
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks (string);
        string printAllBooks();
        string printAllBooksByAuthor(string);
        int readRatings(string);
        int getRating(string, string);
        int getCountReadBooks(string);
        
    private:
        string username;
        const static int sizeBook = 50;
        const static int sizeUser = 100;
        int numBooks;
        int numUsers;
}
;
#endif
