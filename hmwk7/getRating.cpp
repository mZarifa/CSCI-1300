// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #7 Problem 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "User.h"
#include "User.cpp"
#include "Book.h"
#include "Book.cpp"
using namespace std;

int getRating(string username, string bookTitle, User users[], Book books[], int numUsers, int numBooks) //create the function with these variables
{
    string usernameUpper = "";  //create a blank string.
    string bookTitleUpper = ""; //create a blank string.
    string tempName; //create a tempName string.
    string tempBook; //create a tempBook string. 
    int userIndex = 0; //create a userIndex and start at 0.
    int bookIndex = 0; //create a bookIndex and start at 0.
    string bookUpper[50]; //create a string called bookUpper and set it to 50.
    string nameUpper[50]; //create a string called nameUpper and set it to 50.
    
    for (int i = 0; i < username.length(); i++) //set a counter i. For i less than the length of username, do the following, then add 1
    {
        bookTitleUpper += toupper(bookTitle[i]); //make bookTitle at array position i capital, then add 1 to i. 
    }
    for (int j = 0; j < bookTitle.length(); j++) //set a counter i. For i less than the length of username, do the following, then add 1
    {
        usernameUpper += toupper(username[j]); //make username at array position j capital, then add 1 to j. 
    }
    
    bool bookExists = false; //create a boolean called bookExists and set it to false.
    bool userExists = false; //create a boolean called UserExists and set it to false. 
    
    for (int i = 0; i < numBooks; i++) // /set a counter i. For i less than the numBooks, do the following, then add 1
    {   
        tempBook = books[i].getTitle(); //set the tempBook string to books at array position i using getTitle.
        for(int j = 0; j < tempBook.length(); j++) //set a counter j, for j less than tempBook.length, add 1 to j.
        {
            bookUpper[i]+=toupper(tempBook[j]); //set bookUppser at array position i to the capital version of whatever is in tempBook at array position j.
        }
    }
    for(int i = 0; i < numUsers; i++) //set a counter i. For i less than the length of numUsers, do the following, then add 1
    {
        tempName = users[i].getUsername(); //set the value tempName to whatever is in users at array position i using the getusername function.
        for(int j = 0; j < tempName.length(); j++) //create an int called j, for j less than tempName.length, add 1 to j.
        {
            nameUpper[i]+=toupper(tempName[j]); //set nameUpper at array position i to the capitalized version of tempName at array position j. 
        }
    }
    
    for (int i = 0; i < numBooks ; i++) //create a counter i, set it to 0, for i less than numbooks, add 1 to i after doing the following. 
    {
        if(bookUpper[i] == bookTitleUpper) //if booksUpper at array position i is the same as bookTitleUpper
        {
            bookExists = true; //set the bookExists boolean to true.
            bookIndex = i; //set the booksIndex to i.
        }
    }
    for (int i = 0; i < numUsers; i++) //counter i, i less than num users, do this stuff then add 1 to i.
    {  
        if (nameUpper[i] == usernameUpper) //if nameUpper at arrayposition i is the same as usernameUpper
        {
            userExists = true; //set userExists to true
            userIndex = i; //set userIndex to i.
        }
    }
    if(!bookExists && !userExists)
    {
        return -3; //if either are false, return -3
    }
    else
    {
        return users[userIndex].getRatingAt(bookIndex); //else, return users[userIndex] using the getRatingAt function with bookIndex position.
    }
}

int main()
{
    User users[50] =  {"Tom", "Mark", "Kyle"};
    Book books[50] = {"The Foundtainhead", "Send Help Please", "This homework is so frustrating bro", "Seg Fault"};
    cout << getRating("Tom", "The Fountainhead", users, books, 5, 4) << endl;
}