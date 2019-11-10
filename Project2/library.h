// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 2 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.h"
#include "User.h"
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
        void printAllBooks();
        void printBooksByAuthor(string);
        int readRatings(string);
        int getRating(string, string);
        int getCountReadBooks(string);
        void viewRatings (string, int);
        double calcAvgRating (string);
        double calcAvgRatingByAuthor(string);
        int addUser (string);
        int checkOutBook (string, string, int);
        void getRecommendations(string);

        
    private:
        string username;
        const static int sizeBook = 50;
        const static int sizeUser = 100;
        Book books[sizeBook];
        User users[sizeUser];
        int numBooks;
        int numUsers;

}
;
#endif
