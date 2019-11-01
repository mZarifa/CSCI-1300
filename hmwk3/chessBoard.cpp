// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 3 - Problem 3

#include <iostream>
using namespace std;

//algorithm: to check what the color of the square is based on the letter/number position.
void chessBoard (char letter1, int num1)
{
    if (num1 > 8 || num1 < 1 || letter1 != 'a' && letter1 != 'b' && letter1 != 'c' && letter1 \
    != 'd' && letter1 != 'e' && letter1 != 'f' && letter1 != 'g' && letter1 != 'h')
    {
        cout << "Chessboard squares can only have letters between a-h and numbers " \
        "between 1-8." << endl;
    } // if the number is greater than 8, and/or the letter isn't a-h, return this quote.
    
    else if (letter1 == 'a' || letter1 == 'c' || letter1 == 'e' || letter1 == 'g')
    {
        if (((num1 % 2 ) == 0))
        {
            cout << "white" <<endl;
        } /*
        if the number entered is divisible by 2, and the letter is a, c, e, or g,
        (check if the remainder is 0) then return the space is white if that is 
        the case
        /**/

        else
        {
            cout << "black" << endl;
        }
    } /*
    if it returns a remainder that isn't 0, then output that the color is black 
    /**/
    
    else if (letter1 == 'b' || letter1 == 'd' || letter1 == 'f' ||letter1 == 'h')
    {
        if (((num1 % 2) == 0))
        {
            cout << "black" << endl;
        }
        else
        {
            cout << "white" <<endl;
        }
    }
}

int main()
{ //test cases
    chessBoard ('b', 9); //test case with letter b, number 9. Should output black
    chessBoard ('b', -3); //test case with letter b, number -3. Should output black. 
}