// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework 2 - Problem 3

#include <iostream>
using namespace std;

void classGreeting (int i)
{
    cout << "Hello, CS " << i << " World!";
}
int main(){
    // test 1
    // expected output
    // Hello, CS 1300 World!
    classGreeting (1300);
    
    // test 2
    // expected output
    // Hello, CS 12 World!
    classGreeting(12);
}