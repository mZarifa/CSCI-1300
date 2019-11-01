// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 2 Problem 1
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Library.h"

using namespace std;

Library :: Library()
{
    username = ""; // set username to blank string.
    numBooks = 0; //set numBooks to 0.
    numUsers = 0; //set numUsers to 0.
}

int Library :: getSizeBook()
{
    return sizeBook;
}
int Library :: getSizeUser()
{
    return numUsers;
}
int Library :: getNumBooks()
{
    return numBooks;
}
int Library :: getNumUsers()
{
    return numUsers;
}

int Library :: readBooks(string input)
{

}
string Library :: printAllBooks()
{

}
string Library :: printAllBooksByAuthor(string input)
{

}
int Library :: readRatings(string fileName)
{
    
}
int Library :: getRating(string inputUser, string bookTitle)
{

}
int Library :: getCountReadBooks(string inputUser)
{

}
