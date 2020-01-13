#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


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


int Count_m_z(string input)
{
    int counter = 0;
    string check = "mnopqrstuvwxyz";
    
    if (input == "")
    {
        return -1;
    }
    for(int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < check.length(); j++)
        {
            if (input[i] == check[j])
            {
                counter++;
            }
        }
    }
    if (counter == 0)
    {
        return -2;
    }
    return counter;
}


string removeDigits(string input)
{
    int help;
    string temp = "";
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] != '0' && input[i] != '1' &&input[i] != '2' &&input[i] != '3' &&input[i] != '4' &&input[i] != '5' &&input[i] != '6' &&input[i] != '7' && input[i] != '8' && input[i] != '9')
        {
            temp = temp + input[i];
        }
    }
    return temp;
}


void printEligiblePlayers(string names[], double array[], int arrSize)
{
    string countryHolder;
    int medalHolder;
    for(int i = 0; i < arrSize; i++)
    {
        if(array[i] >= 4 && array[i] <= 6)
        cout << names[i] << " " << array[i] << endl;
    }
}

int calcCost(string fileName)
{
    int linecount;
    ifstream in_file; //declares the file input variable
    in_file.open(fileName); //opens the file in in_file
    string numtemp;

    string line = "";
    string name;
    string temparr[3];
    float total;
    linecount = 0;
    if (in_file.fail()) //but if file opening fails.
    {
        return -1; //return -1 if it doesn't exist. 
    }
    
    if (in_file.is_open()) //if its open, do the following
    {
        while (getline(in_file, line)) 
        {
            if(line != "") //if its blank
            {
                float int1 = 0.000;
                float int2 = 0.000;
                float int3 = 0.000;
                split(line, ',', temparr, 3); //do the split function with the following.
                name = temparr[0];
                int1= stod(temparr[1]);
                int2 = stod(temparr[2]);
                int3 = int1 * int2;
                total = total + int3;
                cout << name << ": " << int3 << endl;
                linecount++;
            }
        }
        in_file.close(); //close the file.
    }
    cout << "Total: " << total << endl;
    return linecount;
}

int main()
{
    cout << calcCost("file.txt");
}


