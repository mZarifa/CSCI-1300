// CS1300 Fall 2019s
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 5

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.h"
#include "Book.cpp"
using namespace std;

//algorithm: print the names and authors of all the books given

void printAllBooks(Book Books[], int numberOfBooks) //create these variables
{
    if (numberOfBooks <= 0) //if the number of books is less than or equal to 0
    {
        cout << "No books are stored" << endl; //output this 
    }
    else
    {
        cout << "Here is a list of books" << endl; //output this line
        
        for(int i = 0; i < numberOfBooks; i++) //for i < the number of books, do the following, then add 1 to i.
        {
            cout << Books[i].getTitle()<<" by " << Books[i].getAuthor() << endl; //output the titles in position i and the authors in position i
        }   
    }
}