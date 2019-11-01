// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #7 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "User.h"
#include "User.cpp"
int main() //test cases for User.cpp
{
    User user; 
    int size = 50;
    int ratings[size];
    User();
    User("Jarvin", ratings, 10);
    
    cout << "Test 1: " << endl;
    
    cout << user.getUsername() << endl;
    user.setUsername("Jax");
    
    cout << user.getRatingAt(1) << endl;
    cout << ratings[1] << endl;
    
    user.setRatingAt(3,7);
    cout << user.getNumRatings() << endl;
    
    user.setNumRatings(2);
    
    cout << user.getSize() << endl;
    // when compiled, file should output blank, 0,0,0,50.
    
    user; 
    size = 30;
    ratings[size];
    User();
    User("Darius", ratings, 8);
    cout << "Test 2: " << endl;
    cout << user.getUsername() << endl;
    user.setUsername("Irelia");
    
    cout << user.getRatingAt(1) << endl;
    cout << ratings[1] << endl;
    
    user.setRatingAt(3,7);
    cout << user.getNumRatings() << endl;
    
    user.setNumRatings(2);
    
    cout << user.getSize() << endl;
} //when compiled, should output Jax, 0, 0, 2, 50.