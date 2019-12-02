// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Homework #8 Problem 1

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//algorithm: to shuffle the two inputted vectors and output them alternating between the two, the larger one first.

vector <int> shuffle(vector<int> in1, vector<int> in2) //two input vectors, in1 and in2
{
    bool checkLarger; //create a true/false to check which is larger
    vector <int> output; //output vector
    
    if (in1.size() == 0 && in2.size() == 0) //if they're both 0
    {
        return output; //return output vector
    }
        
    if(in1.size() > in2.size()) //if 1 is greater than 2
    {
        checkLarger = true; //its true then (https://i.imgur.com/2DHY3Hx.jpg)
    }

    else if(in2.size() > in1.size()) //if 2 is greater than 1
    {
        checkLarger = false; //false bruh
    }

     else
     {
        for (int i = 0; i < in1.size(); i++)
        {
            output.push_back(in1[i]); 
            output.push_back(in2[i]); //fill the vector array from the back, starting with vector 1 by default
        }
        return output;
     }
        
    if(checkLarger) //if its true
    {
        for(int i = 0; i < in2.size(); i++) //for i < the size of vector 2, do the following, then add 1 to i.
        {
            output.push_back(in1[i]);
            output.push_back(in2[i]); //fill the vector array from the back, starting with vector 1 by default, then go to vector 2
        }
        for(int i = in2.size(); i < in1.size(); i++) //set i to the size of vector 2, and while its smaller than the size of the 1st vector
        {
            output.push_back(in1[i]); //then fill the rest with the final values of vector 1
        }
        return output;
    }

    else if (!checkLarger) //but if its false
    {
        for (int i = 0; i < in1.size(); i++)
        {
            output.push_back(in2[i]); //fill the vector array from the back, starting with vector 2 instead, because its bigger
            output.push_back(in1[i]);
        }

        for(int i = in1.size(); i < in2.size(); i++) //set i to the size of vector 1... and while its its less than the size of the 2nd vector...
        {
            output.push_back(in2[i]); //then fill the rest with the final values of vector 2
        }
        return output;
    }
}

int main()//test cases
{
    
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1, v2);
    cout << "Test 1: ";
    for (int i=0; i < v3.size(); i++) 
    {
        cout << v3[i] << " "; //should output 2 1 4 3 6 5 8 9 10
    }
    cout << endl;

    vector<int> v4{1,3,5,9};
    vector<int> v5{};
    vector<int> v6 = shuffle(v4, v5);
    cout << "Test 2: ";
    for (int i=0; i < v6.size(); i++) 
    {
        cout << v6[i] << " "; //should output 1,3,5,9
    }
}