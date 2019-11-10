// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 2 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.cpp"
#include "Library.cpp"
#include "User.cpp"

int main()
{	
Library l33 = Library();
int numBooks = l33.readBooks("books.txt");
int numUsers = l33.readRatings("ratings.txt");

//l9.viewRatings("rebecca", 3);
double count2 = l33.calcAvgRatingByAuthor("Neil Shusterman");
cout << "calcAverageRatingByAuthor returned: " << count2 << endl;

/*Library l24 = Library();
int numBooks = l24.readBooks("books.txt");
int numUsers = l24.readRatings("ratings.txt");
l24.viewRatings("cannot_find_me", 2); */

/*Library l15 = Library();
int numBooks = l15.readBooks("books.txt");
int numUsers = l15.readRatings("ratings.txt");
cout << "numUsers(before) = " << l15.getNumUsers() << endl;

// checking the num users
int rv =  l15.addUser("oogabooga");
cout << "addUser returned: " << rv << endl;
cout << "numUsers (after)= " << l15.getNumUsers() << endl;

// check if we can find the newUser
int count = l15.getCountReadBooks("oogabooga");
cout << "getCountReadBooks returned: " << count << endl;*/

	
//checkoutBook : initialized, invalid rating
	
//checkoutBook : success with updating the rating
/*Library l22 = Library();
int numBooks = l22.readBooks("books.txt");
int numUsers = l22.readRatings("ratings.txt");
cout << "rating (before) = " << l22.getRating("sharon", "Watership Down") << endl;
int rv = l22.checkOutBook("sharon","Watership Down",5);
cout << "Returned : "<< rv <<endl;
cout << "rating (after) = " << l22.getRating("sharon", "Watership Down");*/
}
