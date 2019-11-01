// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #7 Problem 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include "Book.h"
using namespace std;

//algorithm: implementation of class Book

Book::Book() //create book definition
{
    title = ""; //set title to blank
    author = ""; //set author to blank
}

Book :: Book(string inputTitle, string inputAuthor)
{
    title = inputTitle; //set input variable inputTitle to title
    author = inputAuthor; //set inputted variable inputAuthor to author
}

string Book :: getTitle() //create getTitle function definition
{
    return title; //return the string of title.
}

void Book :: setTitle(string inputTitle) //create the function of set title with input of inputTitle.
{
    title = inputTitle; //set title to inputTitle.
}

string Book :: getAuthor() //create the getAuthor definition
{
    return author; //return the author string
}

void Book :: setAuthor(string inputAuthor) //create the function definition setAuthor with input 
{
    author = inputAuthor; //return the string of author.
}