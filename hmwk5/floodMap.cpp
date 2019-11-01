// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #5 Problem 5

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;
//algorithm: flood map output

void floodMap(double map[][4], int rows, double waterLevel) //create these variables
{
    for(int i = 0; i < rows; i++) //for i < the number of rows, do the following, and then i + 1
    {
        for(int j = 0; j < 4; j++) //while j is less than 4 (given) do the following and then j + 1
        {
            if(map[i][j] <= waterLevel) //if the array map at the position i, j is less than the waterLevel given
                cout << "*"; //output that *
            else
                cout << "_"; //else output the _
        }
        cout << endl; //end the line
    }
}
int main()
{ //test 1:
    cout << "test 1: " << endl;
    double map[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928}, 
    {16.8498, 5.736, 9.33342, 6.36095}, 
    {3.18645, 16.935, 4.7506, 9.63635}, 
    {2.22407, 0.815145, 0.298158, 13.466}};
    floodMap(map, 4, 9.3);
    
   //test 2:
   cout << "test 2: " << endl;
    double map2[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928}, 
    {16.8498, 5.736, 9.33342, 6.36095}, 
    {3.18645, 16.935, 4.7506, 9.63635}, 
    {2.22407, 0.815145, 0.298158, 13.466}};
    floodMap(map2, 4, 7);
    
}