// CS1300 Fall 2019s
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

//print the names and authors of all the books given

void printAllBooks(string titles[], string authors[], int numberOfBooks) //create these variables
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
            cout << titles[i]<<" by " << authors[i] << endl; //output the titles in position i and the authors in position i
        }   
    }
}

int main()
{
    string book_titles[] = {"Calculus", "Algebra", "Physics"};
    string book_authors[] = {"Gottfried Leibniz", "Alan Turing", "Isaac Newton"};
    cout << "Test 1: " << endl; //test with stuff. Should return "book by author" for every line. 
    printAllBooks (book_titles, book_authors, 3);
    
    cout << endl;
    
    string book_titles2[] = {};
    string book_authors2[] = {};
    cout << "Test 2: " << endl; ////test with blanks and a 0, should return "no books are stored"
    printAllBooks(book_titles2, book_authors2, 0);
    
    cout << endl;
    
    string book_titles3[] = {};
    string book_authors3[] = {};
    cout << "Test 3: " << endl; //test with negative numbers, should return "no books are stored"
    printAllBooks(book_titles3, book_authors3, -1);
    
    
    
}