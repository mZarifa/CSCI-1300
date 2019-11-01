// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.h"
#include "Book.cpp"
using namespace std;

int main()
{
    Book book;
    
    Book();
    cout << "Test 1: " << endl;
    Book("Great book", "Actually not me");
    cout << book.getTitle() << endl; //should output nothing
    book.setTitle("League of Legends");
    cout << book.getTitle() << endl; //should output the book title League of Legends
    book.setAuthor("Riot Games");
    cout << book.getAuthor() << endl; //should output Riot Games
    cout << endl;
    
    cout << "Test 2: " << endl;
    Book("C++ God", "Every 1300 Student Ever");
    cout << book.getTitle() << endl; //should output League of Legends (from the previous test)
    book.setTitle("Tom Clancy's Rainbow 6: Siege");
    cout << book.getTitle() << endl; //should output the book title "Tom Clancy's..."
    book.setAuthor("Ubisoft");
    cout << book.getAuthor() << endl; //should output Ubisoft
    cout << endl;
}