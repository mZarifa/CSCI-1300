// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 7

#include <iostream>
using namespace std;

//algorithm: to print values for the entire collatz sequence from the starting #.
void printCollatz(int n) 
{
    if (n <= 0)
    {
     cout << "invalid number" <<endl;
    } // if the starting number is less than 0, say "invalid number"
    
     else
     {
         cout << n << " "; //print that starting number
         while (n != 1) //while n doesnt equal 1, do the following...
         {
             if ((n % 2) == 1) /* if n returns a remainder when divided by 2
                                  (its odd) then... */
             {
                 n = 3*n + 1; //multiply by 3 and add 1
                 cout << n << " "; //output the new n value.
             }
        else
        {
            n = n / 2; //divide n by 2.
            cout << n << " ";
        }
        }
    }
}
   
int main()
{
   printCollatz (-5);   //test with an input of zero
   printCollatz(6);     //test with an input of 6
}
