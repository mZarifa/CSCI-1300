// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 4

#include <iostream>
using namespace std;

// algorithm: count the number of digits in an inputted value.

int countDigits (int number1)
{
    int count = 0; //set the value for the counter to equal 0
    if (number1 == 0)
    {
        count = 1;
    } 
    // if the number is equal to 0, then set the value for the # of digits to 1 
    
    while (number1 > 0 || number1 < 0)
    {
        number1 = (number1 / 10);
        ++count;
    } /*if the number is greater than or less than 0, take that number and divide
    it by 10. Then add +1 to the counter. Then repeat the process.*/
    return count;
}
int main()
{ //test cases
    countDigits (10000);
    countDigits (-32);
    countDigits (3.9995);
}