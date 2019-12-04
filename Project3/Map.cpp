#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "Map.h"

using namespace std;

void split2(string line, char deliminator, string words[], int arrSize) //create the variables
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

Map::Map()
{
    theMap = {};
}

Map::Map(string fileName) //function for reading the roster.
{
    string newMap[25];
    string line = ""; //create a string called line, and make it blank.
    string tempArray[25]; //create a temp array string with size of 3 for the name, players, and the points.
    
    ifstream in_file;
    in_file.open(fileName); //open the file
    
    if(in_file.is_open()) //if its open
    {
        while (getline(in_file, line)) //while its open
        {
            split2(line, ',', tempArray, 25); //run the split function
            for (int i = 0; i < 25; i++)
            {
                newMap[i] = tempArray[i];
                theMap.push_back(newMap[i]);
            }
        }
        in_file.close(); //close the file.
    }
}

void Map::readMap(string fileName) //function for reading the roster.
{
    string newMap;
    string line = ""; //create a string called line, and make it blank.
    string tempArray[25]; //create a temp array string with size of 3 for the name, players, and the points.
    
    ifstream in_file;
    in_file.open(fileName); //open the file
    
    if(in_file.is_open()) //if its open
    {
        while (getline(in_file, line)) //while its open
        {
            for (int i = 0; i < 25; i++)
            {
                split2(line, ',', tempArray, 16); //run the split function
                newMap = tempArray[i];
                cout << "line1 done" << endl;
                theMap.push_back(newMap);
            }
        }
        in_file.close(); //close the file.
    }
}
void Map :: outputMap()
{
    for(int i = 0; i < 25; i++)
    {
        cout << theMap[i];
    }
}
