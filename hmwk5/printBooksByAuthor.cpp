// CS1300 Fall 2019s
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 6

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

// algorithm: to print the books by a certain author.
void printBooksByAuthor(string titles[], string authors[], int numberOfBooks, string author) //create the variables and strings. 
{
    if (numberOfBooks <= 0) //if the number of books is less than or equal to 0
    {
        cout << "No books are stored" << endl; // output that
        return; //end the code
    }
    int counter = 0; //create a counter and set it to 0.
    for(int i = 0; i < numberOfBooks; i++) //for (create an int called i) i less than the number of books, do the following and then add 1 to i
    {
        if (authors[i] != author) //if the array authors in position i doesn't equal the given author name
        {
            counter = counter + 1; //add 1 to the counter
        }
    }
    if (counter == numberOfBooks) //if the counter is the same as the number of books by the end of all this
    {
        cout << "There are no books by " << author << endl; //output this junk.
        return; //end the code
    }
    else
    {
        cout << "Here is a list of books by " << author << endl; //say this stuff 
        for(int i = 0; i < numberOfBooks; i++) //for (create an int called i) i less than the number of books, do the following and then add 1 to i
        {
            if (authors[i] == author) //if the array authors in position i DOES equal the given author name
            {
                cout << titles[i] << endl; //output the book in position i in the array. 
            }
        }
    }
}

int main()
{
    string titles[3] = {"Book 1", "Book 2", "Book 3"};
    string authors[3] = {"Author A", "Author A", "Author A"};
    int numBooks = 3;
    string author = "Author B";
    cout << "Test 1: " << endl; ////test with no matching authors should output "no books by..."
    printBooksByAuthor(titles, authors, numBooks, author);
    cout << endl;
    
    string titles2[3] = {"Book 1", "Book 2", "Book 3"};
    string authors2[3] = {"Author A", "Author A", "Author A"};
    int numBooks2 = 3;
    string author2 = "Author A";
    cout << "Test 2: " << endl; ////test with all matches, should output "here is a list..." and then the books
    printBooksByAuthor(titles2, authors2, numBooks2, author2);
}