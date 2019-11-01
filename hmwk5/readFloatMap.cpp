// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 6

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

//algorithm: to read the floatMap given from a file. 

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


int readFloatMap(string fileName, double floatMap[][4], int rows) //create the variables
{
    ifstream in_file;
    in_file.open(fileName); //open the files
    string line = ""; //set a string called line to blank
    int counter = 0; //set a counter to 0
    string temparr[4]; //create a temp array with 4 lines
    if (in_file.is_open()) //if the file is open
    {
        while(getline(in_file, line)) //while the file is open...
        {
            if (line != "") //if its blank
            {
                split(line, ',', temparr, 4); //do the split function
                for (int i = 0; i < 4; i++) //for i less than 4
                {
                    floatMap[counter][i] = stod(temparr[i]); //set the floatMap array at counter, i to the storied dobule at temparray i
                }
                counter++; //add 1 to the counter
                
                if(counter == rows) //if the counter is the same as rows
                {
                    break; //end the code
                }
            }
        }
        in_file.close(); //closes file
        return counter; //returns number of lines in file
    }
    else if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }
}
int main()
{ 
    double floatMap[2][4];
    int x = readFloatMap("floodMap.txt", floatMap, 2);
    cout << "Function returned: " << x << "\n";
    
    cout << "Test 1: " << endl;
    for(int i = 0; i < 2; i++)
    {
        // test 1
        cout << floatMap[i][0] << ", " << floatMap[i][1] << ", " << floatMap[i][2] << ", " << floatMap[i][3] << "\n";
    }
    
    
    double floatMap2[2][4];
    int x2 = readFloatMap("floodMap2.txt", floatMap, 2);
    cout << "Function test 2 returned: " << x2 << "\n"; //should return -2 and stop. 
}
