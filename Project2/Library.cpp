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


string makelower(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        input[i] = tolower(input[i]);
    }
    return input; //a function to make whatever is inputted lowercase, using tolower. Helps clean up code. Then returns the string of whatever was inputted but all lowercase. 
}

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
    return sizeUser;
}
int Library :: getNumBooks()
{
    return numBooks;
}
int Library :: getNumUsers()
{
    return numUsers;
}

int Library :: readBooks(string fileName) //create these variables
{
    string line = ""; //set a line to blank
    int bookCount = 0; //set a variable books to blank
    string temparr[2]; //create an array with 2 rows.
    
    if (numBooks == sizeBook) //if the number of books stored is the same as size
    {
        return -2;
    }
    
    ifstream in_file;
    in_file.open(fileName); //open the files
    
    if (in_file.is_open()) //if its open, do the following
    {
        while (getline(in_file, line) && numBooks + bookCount < sizeBook)  //while the file is on that line, and the number of books stored + books is less than the given size do the following. 
        {
        
            if(line != "") //if its blank
            {
                split(line, ',', temparr, 2); //do the split function with the following.
                books[numBooks].setTitle(temparr[1]); //put the titles in temparray 1
                books[numBooks].setAuthor(temparr[0]); //put the authors in temparray 0
                
               numBooks++; //add 1 to the number of books stored.
            }
        }
        
        in_file.close(); //close the file
        
        if (numBooks == sizeBook) //if the numberofbooks stored is the same as size
        {
            return bookCount + numBooks; //return that value
        }
        if (numBooks > sizeBook) //if its greater
        {
            return -2; //return -3
        }
        else
        {
            return bookCount + numBooks; //else, return that. 
        }
    }
    else if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }   
}

void Library :: printAllBooks()
{
    int numberOfBooks = numBooks;
    if (numberOfBooks <= 0) //if the number of books is less than or equal to 0
    {
        cout << "No books are stored" << endl; //output this 
    }
    else
    {
        cout << "Here is a list of books" << endl; //output this line
        
        for(int i = 0; i < numberOfBooks; i++) //for i < the number of books, do the following, then add 1 to i.
        {
            cout << books[i].getTitle()<<" by " << books[i].getAuthor() << endl; //output the titles in position i and the authors in position i
        }   
    }
}

void Library :: printBooksByAuthor(string author)
{
    int numberOfBooks = numBooks;
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

int Library :: readRatings(string fileName)
{
    int maxColumns = 50;

    ifstream in_file; 
    in_file.open(fileName); //open the files
    string line = ""; //create a string called line and make it blank
    int counter = numUsers; //create a counter and set to 0
    string temparr[51] = {""}; //create a temp array with 51 values, instead of 50 (1 for the user and then their 50 ratings)
    if(numUsers >= sizeUser) //if the number of users is the same as the set max rows or greater than...
    {
        return -2; //return -2.
    }
    if (in_file.is_open()) //if the file is able to be opened...
    {
        if(numUsers > 0) //if the number of users is greater than 0
        {
            counter = numUsers; //set that to the counter
        }
         while(getline(in_file,line) && numUsers < sizeUser)
        {
            if (line.length() != 0) //if the length of the line isnt 0
            {
                split(line, ',', temparr, maxColumns + 1); //run the split function
                users[counter].setUsername(temparr[0]); //set the array users in the counter position to the temp array at 0.
                for (int i = 1; i < maxColumns + 1; i++)
                {
                    if(temparr[i] != "") //if the temp array in position i isnt blank
                    {
                        users[counter].setRatingAt(i - 1, stoi(temparr[i])); //set the ratings at the position counter, i-1 to the temparray at point i passed as an integer. 
                    }
                }
                counter++; //add 1 to the counter
                numUsers++;
            }
        }
        
        in_file.close(); //closes file
        return counter;
    }
    else if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }
}


int Library :: getRating(string username, string bookTitle)
{
    int userIndex = 0; //create a userIndex and start at 0.
    int bookIndex = 0; //create a bookIndex and start at 0.
    bool bookExists = false;
    bool userExists = false;
    
    for(int i = 0; i < numBooks; i++)
    {
        if(makelower(books[i].getTitle()) == makelower(bookTitle)) //if the book at i is the same as the inputted title
        {
            bookIndex= i; //set book index to i
            bookExists = true; //set to true
        }
    }

    for(int i = 0; i < numUsers; i++)
    {
        if(makelower(users[i].getUsername()) == makelower(username)) //if the username at point i and inputted username 
        {
            userIndex = i; //user index to i
            userExists = true; //true baby
        }
    }

    if(bookExists == false || userExists == false)
        {
            return -3; //if either false, return -3.
        }
    else
    {
        return users[userIndex].getRatingAt(bookIndex);
    }  
}



int Library :: getCountReadBooks(string username)
{
    int userIndex = 0; //create a userIndex and start at 0.
    bool userExists = false;
    for(int i = 0; i < numUsers; i++)
    {
        if(makelower(users[i].getUsername()) == makelower(username))
        {
            userIndex = i;
            userExists = true;
        }
    }
    if(userExists == false)
    {
        return -3; //if either are false, return -3
    }

    int ratecounter = 0;
    for(int i = 0; i < numBooks; i++) //set a counter i. For i less than the length of numUsers, do the following, then add 1
    {
        if(users[userIndex].getRatingAt(i) != 0) //set the value tempName to whatever is in users at array position i using the getusername function.
        {
            ratecounter++;
        }
    }
    return ratecounter;
}

void Library :: viewRatings(string username, int minValue)
{
    int userIndex = 0; //create a userIndex and start at 0.
    int bookIndex = 0; //create a bookIndex and start at 0.
    bool bookExists = false;
    bool userExists = false;

    for(int i = 0; i < numUsers; i++)
    {
        if(makelower(users[i].getUsername()) == makelower(username))
        {
            userIndex = i;
            userExists = true;
        }
    }

    if(userExists == false)
    {
        cout << username << " does not exist." << endl; //if either are false, return -3
        return;
    }
    else{
    int check0 = 0;
    for(int i = 0; i < numBooks; i++) //set a counter i. For i less than the length of numUsers, do the following, then add 1
    {
        if(users[userIndex].getRatingAt(i) == 0) //set the value tempName to whatever is in users at array position i using the getusername function.
        {
            check0++;
        }
    }
    if (check0 == numBooks)
    {
        cout << username << " has not rated any books yet." << endl;
        return;
    }

    else
    {
        cout << "Here are the books that " << username << " rated" << endl;
        for(int i = 0; i < numBooks; i++) //set a counter i. For i less than the length of numUsers, do the following, then add 1
        {
            if(users[userIndex].getRatingAt(i) >= minValue) //set the value tempName to whatever is in users at array position i using the getusername function.
            {
                cout << "Title : " << books[i].getTitle() << endl;
                cout << "Rating : " << users[userIndex].getRatingAt(i) << endl;
                cout << "-----" << endl;
            }
        }
    }
    }
}


double Library :: calcAvgRating(string bookTitle)
{
    double numerator;
    double totalRate = 0;
    double countNotZero = 0; 
    int userIndex = 0; 
    int bookIndex = 0; 
    bool bookExists = false;
    bool userExists = false; //create this stuff, set bools to false by default. Run checks previously run for lowercase user and book title. 
    
    for(int i = 0; i < numBooks; i++)
    {
        if(makelower(books[i].getTitle()) == makelower(bookTitle))
        {
            bookIndex= i;
            bookExists = true;
        }
    }

    for(int i = 0; i < numUsers; i++)
    {
        if(makelower(users[i].getUsername()) == makelower(username))
        {
            userIndex = i;
            userExists = true;
        }
    }

    if(bookExists == false || numUsers == 0 || numBooks == 0)
    {
        return -3; //if either are false, return -3
    }
    else
    {
        for (int i = 0; i < numBooks; i++)
        {
            if(users[i].getRatingAt(bookIndex) != 0)
            {
                countNotZero++;
                numerator += users[i].getRatingAt(bookIndex); //if its not 0, add 1 to countNotZero (the denom) and set the numerator to whatever it was previously plus the rating.

            }
        }
        if (countNotZero == 0)
        {
            return 0; //dont divide by 0 lol. 
        }
        return (numerator/countNotZero); //divide numerator by denom (countNotZero)
     }
}
double Library :: calcAvgRatingByAuthor(string authorname)
{
    double numerator = 0;
    double totalRate = 0;
    double countNotZero = 0;
    bool authExists = false; //create a boolean called authExists and set it to false.
    int lineIndex = 0;
    for(int i = 0; i < numBooks; i++)
    {
        if(makelower(books[i].getAuthor()) == makelower(authorname))
        {
            authExists = true; //set the bookExists boolean to true.
        }
    }
    if(!authExists)
    {
        return -3; //if either are false, return -3
    }
    else
    {
        for (int i = 0; i < numUsers; i++)
        {
            for (int j = 0; j < numBooks; j++) //running through 2 indexes, i for users, and j for books.
            {
                if(makelower(books[j].getAuthor()) == makelower(authorname)) //if the authornames match at point j through the parse
                {
                    if(users[i].getRatingAt(j)!= 0) //if the user at point i hasn't given it a 0
                    {
                        countNotZero++; //add 1 to countNotZero
                        numerator = numerator + users[i].getRatingAt(j); //set numerator to this stuff
                    }
                }
            }
        }
    }
        if (countNotZero == 0)
        {
            return 0;
        }
        return (numerator/countNotZero);
}

int Library :: addUser(string inputUser)
{
    if(sizeUser == numUsers)
    {
        return -2; //if users full, return -2
    }
    else if(numUsers < sizeUser)
    {
        for(int i = 0; i < numUsers; i++)
        {
            if(makelower(users[i].getUsername()) == makelower(inputUser)) //make the username lowercase, and if it exists already, reutrn -1
            {
                return 0;
            }
        }
    }
    users[numUsers].setUsername(inputUser); //else, set username in the database
    numUsers++; //add 1 to numUsers
    for(int i = 0; i < numBooks; i++)
    {
        users[numUsers].setRatingAt(i, 0); //set all their possible ratings to 0.
    }
    return 1; //output 1.


}
int Library :: checkOutBook (string username, string bookTitle, int newRating)
{
    int userIndex = 0; //create a userIndex and start at 0.
    int bookIndex = 0; //create a bookIndex and start at 0.
    bool bookExists = false;
    bool userExists = false;
    
    for(int i = 0; i < numBooks; i++)
    {
        if(makelower(books[i].getTitle()) == makelower(bookTitle))
        {
            bookIndex = i;
            bookExists = true;
        }
    }

    for(int i = 0; i < numUsers; i++)
    {
        if(makelower(users[i].getUsername()) == makelower(username))
        {
            userIndex = i;
            userExists = true;
        }
    }

    if(newRating > 5 || newRating < 0)
    {
        return -4; //if its not on the scale, return -4
    }

    if(bookExists == false || userExists == false)
    {
        return -3; //if the user or book doesn't exist, return -3
    }

    else
    {
        users[userIndex].setRatingAt(bookIndex, newRating);
        return 1; //else, set that rating baby. 
    }  
}
void Library :: getRecommendations(string username)
{
    return; //unfinished function, it hates me lowkey bro. 
}

