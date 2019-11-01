// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book
{
    public:
        Book();
        Book(string, string);
        string getTitle();
        void setTitle(string);
        string getAuthor();
        void setAuthor(string);
        
    private:
        string title;
        string author;
}
;
#endif