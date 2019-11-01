// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #6 Problem 7

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.h"
#include "Book.cpp"

using namespace std;


//algorithm: to read the books in a file and output the title and author. 

void split(string line, char deliminator, string words[], int arrSize) //create the variables
{
    
    string temp = ""; //create a string that is blank.
    int arrayposition = 0; //create a position holder.
    
    for (int i = 0; i < line.length(); i++) //for i less than the length of the line, do the following
    {
        if( line[i] != deliminator) //if the character in the line i isn't the deliminator
        {
            temp = temp + line[i]; //set the temp string to whatever was in it plus that character
        }
        else
        {
            if (i != 0 && i != (line.length() - 1)) // if i isn't 0, and isn't 1 less than the length of the string...
            words[arrayposition] = temp; //set the array of words at the given position to the temp string
            temp = ""; //set the temp string to blank
            arrayposition++; //add 1 to the arrayposition
            
            int check = i + 1; //create a match check, at i + 1
            if (line[check] == deliminator) //if the line at the checker is the deliminator
            {
                i++; //add 1 to i.
            }
            else
            {
                if (i == line.length() - 1) // if i is the same length as the inputted line - 1.
                {
                    i++; //add 1 to i.
                }
            }
        }
    }
    words[arrayposition] = temp; //set the string 'words' to whatever is in temp at the moment. 
}

int readBooks(string fileName, Book books[], int numBookStored, int size) //create these variables
{
    string line = ""; //set a line to blank
    int bookCount = 0; //set a variable books to blank
    string temparr[2]; //create an array with 2 rows.
    
    if (numBookStored == size) //if the number of books stored is the same as size
    {
        return -2;
    }
    
    ifstream in_file;
    in_file.open(fileName); //open the files
    
    if (in_file.is_open()) //if its open, do the following
    {
        while (getline(in_file, line) && numBookStored + bookCount < size)  //while the file is on that line, and the number of books stored + books is less than the given size do the following. 
        {
        
            if(line != "") //if its blank
            {
                split(line, ',', temparr, 2); //do the split function with the following.
                books[numBookStored].setTitle(temparr[1]); //put the titles in temparray 1
                books[numBookStored].setAuthor (temparr[0]); //put the authors in temparray 0
                
               numBookStored++; //add 1 to the number of books stored.
            }
        }
        
        in_file.close(); //close the file
        
		if (numBookStored >= size) //if books stored is equal to array size
		{
			return -3;
		}
        else
        {//all other cases, return books stored
        return numBookStored;
        }
    }
    else if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }
}




void printAllBooks(Book Books[50], int numberOfBooks) //create these variables
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
        	if(Books[i].getTitle()!="" && Books[i].getAuthor()!="")
        	{
            cout << Books[i].getTitle() << " by " << Books[i].getAuthor() << endl; //output the titles in position i and the authors in position i
        	}
        }   
    }
}



void printBooksByAuthor(Book books[50], int numberOfBooks, string author) //create the variables and strings. 
{
    if (numberOfBooks <= 0) //if the number of books is less than or equal to 0
    {
        cout << "No books are stored" << endl; // output that
        return; //end the code
    }
    int counter = 0; //create a counter and set it to 0.
    for(int i = 0; i < numberOfBooks; i++) //for (create an int called i) i less than the number of books, do the following and then add 1 to i
    {
        if (books[i].getAuthor() != author) //if the array authors in position i doesn't equal the given author name
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
            if (books[i].getAuthor() == author) //if the array authors in position i DOES equal the given author name
            {
                cout << books[i].getTitle() << endl; //output the book in position i in the array. 
            }
        }
    }
}



int main()
{
	int menuInput;
    Book books[50];
    string fileName = "";
    int librarycount;
    int bookIndex = 0;
    
    while (menuInput != 4)
    {
        cout <<"======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Print all books" << endl;
        cout << "3. Print books by author" << endl;
        cout << "4. Quit" << endl;
        cin >> menuInput;
        
        switch(menuInput)
        {
            case 1:
            {
               fileName = "";
               cout << "Enter a book file name: "<< endl;
               cin >> fileName;
               librarycount = readBooks(fileName, books, librarycount, 50);
               if (librarycount == -1)
               {
                   cout << "No books saved to the database." << endl;
               }
               else if (librarycount == -2)
               {
                   cout << "Database is already full. No books were added."<< endl;
               }
               else if (librarycount == -3)
               {
                   cout <<"Database is full. Some books may have not been added."<< endl;
               }
               else
               {
                   cout << "Total books in the database: " << librarycount << endl;
                   bookIndex = librarycount;
               }
               break;
            }
            
            case 2:
            {
                printAllBooks(books, 50); 
                break;
            }
            
            case 3:
            {
                string author = "";
                cout << "Enter name of author: " << endl;
                cin.ignore();
                getline (cin, author);
                printBooksByAuthor (books, 50, author);
                break;
            }
            case 4: 
            {
                cout << "Good bye!" << endl; 
                break;
            }
            default: 
            {
                cout << "Invalid input." << endl; 
                break;
            }
        }
    }
}
