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


vector <int> shuffle(vector<int> in1, vector<int> in2)
{
    bool checkLarger;
    vector <int> output;
    
    if (in1.size() == 0 && in2.size() == 0)
    {
        return output;
    }
        
    if(in1.size()>in2.size())
    {
        checkLarger = true;
    }
    else if (in2.size()>in1.size())
    {
        checkLarger = false;
    }
     else
     {
        for (int i = 0; i< in1.size(); i++)
        {
            output.push_back(in1[i]);
            output.push_back(in2[i]);
        }
        return output;
     }
        
    if(checkLarger)
    {
        for (int i = 0; i < in2.size(); i++)
        {
            output.push_back(in1[i]);
            output.push_back(in2[i]);
        }
        for(int i = in2.size(); i < in1.size(); i++)
        {
            output.push_back(in1[i]);
        }
        return output;
    }

    else if (!checkLarger)
    {
        for (int i = 0; i< in1.size(); i++){
            output.push_back(in2[i]);
            output.push_back(in1[i]);
        }
        for(int i = in1.size(); i< in2.size(); i++)
        {
            output.push_back(in2[i]);
        }
    
        return output;
    }
}
int main()
{
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);

    for (int i=0; i < v3.size(); i++) 
    {
        cout << v3[i] << " ";
    }
}