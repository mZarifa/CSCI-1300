// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 1

#include <iostream>
using namespace std;

//algorithm: to return values for next in the collatz sequence:
int collatzStep(int n)
{
    if (n < 0) //if the number entered is less than zero, return that number.
    {
        n = 0;
    }
    
    else if ((n % 2) == 0) // check if the n even (divisible by 2, and results in no remainder)
    {
        n = n / 2; //divide that number by 2 
    }
    
    else
    {
       n = 3*n +1; //multiply that number by 3, and then add 1
    }
    
return n; //return the value of n
}

//test
int main()
{
   cout << collatzStep(0) << endl; //test with an input of zero
   cout << collatzStep(13) << endl; //test with an input of 13
}
