// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 2

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

//use the split function to read the books in the file

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

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) //create these variables
{
    string line = ""; //set a line to blank
    int books = 0; //set a variable books to blank
    string temparr[2]; //create an array with 2 rows.
    
    if (numBookStored == size) //if the number of books stored is the same as size
    {
        return -2;
    }
    
    ifstream in_file;
    in_file.open(fileName); //open the files
    
    if (in_file.is_open()) //if its open, do the following
    {
        while (getline(in_file, line) && numBookStored + books < size)  //while the file is on that line, and the number of books stored + books is less than the given size do the following. 
        {
        
            if(line != "") //if its blank
            {
                split(line, ',', temparr, 2); //do the split function with the following.
                titles[numBookStored] = temparr[1]; //put the titles in temparray 1
                authors[numBookStored] = temparr[0]; //put the authors in temparray 0
                
               numBookStored++; //add 1 to the number of books stored.
            }
        }
        
        in_file.close(); //close the file
        
        if (numBookStored == size) //if the numberofbooks stored is the same as size
        {
            return books + numBookStored; //return that value
        }
        if (numBookStored > size) //if its greater
        {
            return -2; //return -2
        }
        else
        {
            return books + numBookStored; //else, return that. 
        }
    }
    else if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }
    
}

int main()
{
    string titlesArr[20], authorsArr[20];
    int nBooks = 0;
    nBooks = readBooks("books.txt", titlesArr, authorsArr, nBooks, 20);
    cout << "test 1: " <<  nBooks << endl; //should return 20. 
    
    string titlesArr2[20], authorsArr2[20];
    int nBooks2 = 0;
    nBooks2 = readBooks("nofile.txt", titlesArr, authorsArr, nBooks, 20);
    cout << "test 2: " <<  nBooks2 << endl; //should return -2 
}