// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #4 Problem 4

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

//algorithm: take the first and last values in an array and swap them
void swapFirstLast(int arr[], int len)
{
    int a = arr[0]; //set an int called 'a' to the first value of the array.
    int b = arr [len - 1]; //test an int called 'b' to the last value of the array
    arr [0] = b; //set the first value to what b was.
    arr [len - 1] = a; //set the last value to what a was.
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl; //the for loop to output the new array. 
    }
    
}
int main()
{
    int arr1[3] = {10, 20, 30}; //test1: should output 30, 20, 10.
    cout << "test 1 : " << endl;
    swapFirstLast(arr1, 3);
    cout << endl;
    
    int arr2[5] = {1, 3, 20, 25, 50}; //test 2: should output 50, 3, 20, 25, 1
    cout << "test 2: " << endl;
    swapFirstLast(arr2, 5);
    cout << endl;
}