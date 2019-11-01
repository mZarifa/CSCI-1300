// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #4 Problem 1

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
    double tempsArray[10];
    for (int i = 0; i < 10; i++)
    {
        tempsArray[i] = -459.67;
        cout << tempsArray[i] << endl;
    }
    
    string colorsArray[5] = { "Red", "Blue", "Green", "Cyan", "Magenta"};
    for (int i = 0; i < 5; i++)
    {
        cout << colorsArray[i] << endl;
    }
    
    int sequenceArray [100];
    for (int i = 0; i < 100; i++)
    {
        sequenceArray[i] = i + 1;
        cout << sequenceArray[i] << endl;
    }
    
    char lettersArray[52];
    for (int i = 0; i < 26; i++)
    {
        lettersArray[i] = i + 65;
        lettersArray[i + 1] = i + 97;
        cout << lettersArray[i] << " " << lettersArray[i + 1] << endl;
    }
}