// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 2

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Library.cpp"
#include "User.cpp"
#include "Book.cpp"

using namespace std;

int menuInput = 0;
string fileName;
string input;
Library bigLib = Library();

void displayMenu()
{
    while (menuInput != 13)
    {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Print all books" << endl;
        cout << "4. Print books by author" << endl;
        cout << "5. Get rating" << endl;
        cout << "6. Find number of books user rated" << endl;
        cout << "7. View ratings" << endl;
        cout << "8. Get average rating" << endl;
        cout << "9. Get average rating by author" << endl;
        cout << "10. Add a user" << endl;
        cout << "11. Checkout a book" << endl;
        cout << "12. Get recommendations" << endl;
        cout << "13. Quit" << endl;
        cin >> menuInput;

        switch(menuInput)
        {
            case 1:
            {
                string input1;
                cout << "Enter a book file name:" << endl;
                cin.ignore();
                getline(cin, input1);
                bigLib.readBooks(input1);
                if(bigLib.getNumBooks() == 0 || bigLib.getNumBooks() == -1)
                {
                    cout << "No books saved to the database." << endl;
                    cin.clear();
                    cout << endl;
                    break;
                }
                else if(bigLib.getNumBooks() == -2)
                {
                    cout << "Database is full. Some books may have not been added." << endl;
                    cout << endl;
                    break;
                }
                else if(bigLib.getNumBooks() >= 50)
                {
                    
                    cout << "Database is already full. No books were added." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "Total books in the database: " << bigLib.getNumBooks() << endl;
                    cout << endl;
                    break;
                }

                break;
            }
            case 2:
            {
                cout << "Enter a user file name: " << endl;
                cin.ignore();
                getline(cin, fileName);
                bigLib.readRatings(fileName);
                if(bigLib.getNumUsers() == -1 || bigLib.getNumUsers() == 0)
                {
                    cout << "No users saved to the database." << endl;
                    cout << endl;
                    break;
                    
                }
                else if(bigLib.getNumUsers() == -2)
                {
                    cout << "Database is full. Some users may have not been added." << endl;
                    cout << endl;
                }
                else if(bigLib.getNumUsers() > 100)
                {
                    cout << "Database is already full. No users were added." << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Total users in the database: " << bigLib.getNumUsers() << endl;
                    cout << endl;
                }
                break;
            }
            case 3:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    bigLib.printAllBooks();
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string input = "";
                    cout << "Enter an author name" << endl;
                    cin.ignore();
                    getline(cin, input);
                    bigLib.printBooksByAuthor(input);
                    cout << endl;
                }
                break;
            }
            case 5:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string input1 = "";
                    string input2 = "";
                    cout << "Enter a user name: " << endl;
                    cin.ignore();
                    getline(cin, input1);
                    cout << "Enter a book title:" << endl;
                    getline(cin, input2);
                    int value = bigLib.getRating(input1, input2);
                    if (value == 0)
                    {
                        cout << input1 << " has not rated " << input2 << endl;
                        cout << endl;
                        break;
                    }
                    else if (value == -3)
                    {
                        cout << input1 << " or " << input2 << " does not exist." << endl;
                        cout << endl;
                    }
                    else
                    {
                        cout << input1 << " rated " << input2 << " with " << value << endl;
                        cout << endl;
                    }
                }
                break;
            }
            case 6:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string userinput = "";
                    cout << "Enter a user name:" << endl;
                    getline(cin, userinput);
                    cin.ignore();
                    int value = bigLib.getCountReadBooks(userinput);
                    if (value == 0)
                    {
                        cout << userinput << " has not rated any books yet" << endl;
                        cout << endl;
                        break;
                    }
                    else if (value == -3)
                    {
                        cout << userinput << " does not exist." << endl;
                        cout << endl;
                        cin.ignore();
                        break;
                    }
                    else
                    {
                        cout << userinput << " rated " << value << "number of books." << endl;
                        cout << endl;
                    }
                }
                break;
            }
            case 7:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string input1;
                    int minValue;
                    cout << "Enter a username: " << endl;
                    cin.ignore();
                    getline(cin, input1);
                    cout << "Enter a min value" << endl;
                    cin.ignore();
                    cin >> minValue;
                    bigLib.viewRatings(input1, minValue);
                    cout << endl;
                    break;
                }
                break;
            }
            case 8:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string input1;
                    cout << "Enter a book title: " << endl;
                    cin.ignore();
                    getline(cin, input1);
                    double value = bigLib.calcAvgRating(input1);
                    if(value == -3)
                    {
                        cout << input1 << " does not exist." << endl;
                        cout << endl;
                        break;
                    }
                    else
                    {
                        cout << "The average rating for " << input1 << " is " << value << endl;
                        cout << endl;
                        break;
                    }
                }
                break;
            }
            case 9:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string input1;
                    cout << "Enter a book title: " << endl;
                    cin.ignore();
                    getline(cin, input1);
                    cout << bigLib.calcAvgRating(input1) << endl;
                    cout << endl;
                    break;
                }
                break;
            }
            case 10:
            {
                {
                    string input1;
                    cout << "Enter a user name:" << endl;
                    cin.ignore();
                    getline(cin, input1);
                    int check = bigLib.addUser(input1);
                    if(check == 1)
                    {
                        cout << "Welcome to the library " << input1 << endl;
                        cout << endl;
                        break;
                    }
                    if(check == 0)
                    {
                        cout << input1 << " already exists in the database." << endl;
                        cout << endl;
                        break;
                    }
                    if(check == -2)
                    {
                        cout << "Database is full. " << input1 << " was not added." << endl;
                        cout << endl;
                        break;
                    }
                }
                 break;   
            }
            case 11:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    string input1;
                    string input2;
                    int input3;
                    cout << "Enter a user name:" << endl;
                    cin.ignore();
                    getline(cin, input1);
                    cout << "Enter a book title:" << endl;
                    getline(cin, input2);
                    cout << "Enter a new rating:" << endl;
                    cin.ignore();
                    cin >> input3;
                    int result = bigLib.checkOutBook(input1, input2, input3);
                    
                    if(result == 1)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                        cout << endl;
                        break;
                    }
                }
            }
            case 12:
            {
                if (bigLib.getNumUsers() == 0 || bigLib.getNumBooks() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "This function is incomplete. I'm really sorry." << endl;
                    cout << endl;
                    break;
                }
                break;
            }
            case 13:
            {
                cout << "Good bye!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid input." << endl;
                cout << endl;
                break;
                if(!(cin >> menuInput))
                {
                    cout << "Invalid input." << endl;
                    cout << endl;
                    cin.ignore(10000,'\n');
                    cin.clear();
                    break;
                }
            } 
        }
    }
}
int main()
{
    displayMenu();
}
