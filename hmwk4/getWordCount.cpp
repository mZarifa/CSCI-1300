// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #4 Problem 5

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;
// algorithm: to get the word count of a given string.

int getWordCount(string sentence) //create function with variable sentence. 
{
    int numberofwords = 0; // Holds number of words 
    
    if (sentence == "") //if the sentence is blank
    {
        return 0; //return 0
    }
    
	for(int i = 0; i < sentence.length(); i++) //create a counter i, and for i less than the length of the inputted sentence, add 1 to i.
	{
		if (sentence[i] == ' ') //Checking for spaces //if there is a space at position i
		{
			numberofwords++; //add 1 to the number of words
		} 		
	}
	return numberofwords + 1; //output the number of words +1
}

int main()
{ //test cases

    string sentence = "Send help please"; 
    cout << "test 1: " << getWordCount (sentence) << endl; //should return 3.
    sentence = "";
    
    cout << "test 2: " << getWordCount (sentence) << endl; //should return 0.
}
