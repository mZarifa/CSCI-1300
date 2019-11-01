// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #4 Problem 2

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

//Algorithm: to print an array in reverse. 

void printArrReverse(int arr[], int len) //create the function with two variables, the array, and the length the array should be.
{
    for (int i = 1; i <= len; i++) //Since array's start at 0, we have to start 1 early to get it to print the first number, so i = 1, and during the time for i less than or equal to the len, add 1 to i
    {
        cout << arr[len-i] << endl; // output the array at the spot (the length of the array - i)
        
    }
}

int main() //test cases
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int len = 10;
    cout << "test 1: " << endl;
    printArrReverse(arr, len);
    cout << endl;
    
    int arr2[] = {1, 9, 7};
    int len2 = 3;
    cout << "test 2: " << endl;
    printArrReverse(arr2, len2);
}