// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 2

#include <iostream>
using namespace std;
//algorithm: to check if 3 inputted variables (input 1, 2, 3) are the same or if some are different.

void checkEqual (int input1, int input2, int input3)
{
    if (input1 == input2 && input1 == input3) 
    {
        cout <<"All same";
    } //if inputs 1, 2, 3 are the same, return "all are the same."
    
    else if (input1 == input2 && input1 !=input3)
    {
        cout << "Neither";
    } //if input 1 and 2 are equal, but 1 doesnt equal 3, then return "neither"
    
    else if (input1 != input2 && input1 == input3)
    {
    cout << "Neither"; 
    } //if input 1 doesn't equal input 2, and input 1 equals input 3 return "neither"
    
    else if (input1 != input2 && input2 == input3)
    {
    cout <<"Neither";
    } //if input 1 doesnt equal input 2, and input 2 equals input 3 return "neither"

    else
    {
        cout << "All different" << endl; //output all different
    }
}
int main()
{
    checkEqual (1, 2, 3);
    checkEqual (6, 6, 6);
}