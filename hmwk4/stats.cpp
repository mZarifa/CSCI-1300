// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #4 Problem 3

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

// algorithm: to print out the largest number, the smallest number and the average of all the numbers in an array

void stats(double arr[], int len) //create the function with two variables, the array, and the length the array should be.
{
    double smallestNumber = arr[0]; //create a variable called smallestNumber, which equals the value for the first point in the array
    for(int i = 0; i < len; i++) // from 0 to the length of the array, do the following and add 1 to i
    {
        if( smallestNumber > arr[i]) //if first number in the array is greater than the previous
        {
            smallestNumber = arr[i]; //set the variable smallestNumber to that number in the array.
        }
    }
    cout << "Min: " << setprecision (2) << fixed << smallestNumber << endl; //output the smallestNumber. 
    
    double largestNumber = arr[0]; //create a variable called largestNumber, which equals the value for the first point in the array
    for(int i = 0; i < len; i++) // from 0 to the length of the array, do the following and add 1 to i
    {
        if( arr[i] > largestNumber) //if next number in the array is greater than the previous number in the array
        {
            largestNumber = arr[i]; //that value becomes the largestNumber. 
        }
    }
    cout << "Max: " << setprecision (2) << fixed << largestNumber << endl; //output the Largest Number.
    
    
    double total = 0; //create a variable called total and set it to 0. 
    for(int i = 0; i < len; i++) // from 0 to the length of the array, do the following and add 1 to i
    {
        total = total + arr[i]; //set total to total + the next number in the array. 
    }
    double average = total / len; //create a double called average which takes the total divided by the length of the array (the average)
    cout << "Avg: " << setprecision (2) << fixed << average << endl; //output the average. 
}


int main ()
{
    double arr[] = {0,1,2,3,4,5,6,7,8,9};
    int len = 10;
    stats(arr, len);
}