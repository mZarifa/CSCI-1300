// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 4

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.h"
#include "readBooks.cpp"
using namespace std;

int main()
{ //test cases for readBooks.cpp
    Book books[10] = {};
    cout << readBooks("books.txt", books, 0, 10) << endl;     //should output 10
    
    Book books2[60] = {};
    cout << readBooks("books.txt", books2, 0, 60) << endl;     //should output 50 as max

    
}
