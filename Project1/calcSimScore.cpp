// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 4

#include <iostream>
#include <string>
using namespace std; 
// Algorithm: to test how similar two given sequences are using the equation: similarity_score = ((string_length - hamming_distance) / (string_length));

double calcSimScore (string seq1, string seq2) //create two strings, seq1 and seq2
{   
    double hamming_distance = 0; //create a variable called hamming_distance, and set it to 0
    double similarity_score = 0; //create the variable for the similarity score, set it to 0
    double string_length = seq1.length(); //create a variable called string length, and set it to the length of the inputted seq1.
    
    if (seq1 == "" || seq2 == "") //if either sequence is blank
    {
        similarity_score = 0;
        return similarity_score; //return a similarity score of 0
    }

    if (seq1.length() != seq2.length()) //if the length of the two sequences are not the same
    {
        similarity_score = 0;
        return similarity_score; //return a similarity score of 0
    }
    
    for (int i = 0; i < seq1.length(); i++) //create an index i, and for i less than the length of sequence, add 1 to i and do the following
    {
        if (seq1[i] != seq2[i]) //if the letter in position 'i' of the two sequences doesnt match
        {
            hamming_distance++; //add 1 to the hamming distance, then do it again
        }
    }
    similarity_score = ((string_length - hamming_distance) / (string_length)); //calculate the sim score. 
    return similarity_score; //return the sim score. 
}

int main()
{
    cout << "test 1: " << calcSimScore("ACGC", "ATGC") << endl; //should return .75
    cout << "test 2: " << calcSimScore("GC", "ATGC") << endl; //should return 0.
    cout << "test 3: " << calcSimScore("", "ATGC") << endl; //should return a value of 0.
    cout << "test 4: " << calcSimScore("aaaa", "") << endl; //should return a value of 0.
}