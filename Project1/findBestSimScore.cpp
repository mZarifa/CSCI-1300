// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 5

#include <iostream>
#include <string>
using namespace std; 
// Algorithm: to test how similar a sequence is to a genome, using the equation: similarity_score = (sequence.length() - hamming_distance) / (sequence.length())

double findBestSimScore(string genome, string sequence) //create the code, and create two strings, a genome string, and a sequence string. 
{
    double bestSimScore = 0; //set the variable bestSimScore to 0. 
    double similarity_score = 0; //create a double, called similarity score, and set it to 0. 

    if (genome.length() >= sequence.length() && sequence.length() != 0) //if the length of the genome is greater than or equal to the length of the sequence
    { //and the length of the sequence isn't 0. 
    
        int instanceStart = 0; //create a variable for the start of the instance, and set it to 0. 
        do //now do the following...
        {
            double hamming_distance = 0; //create the hamming distance variable, and set it to 0.
            
            string genomeInstance = genome.substr(instanceStart, sequence.length()); /*create a string called genomeInstance, and it equals the substring of the genome string
            from the start of the instance, to the length of the sequence */
            
            int i = 0; //create a counter variable called i, and set it to 0. 
            
            while (i <= genomeInstance.length()) //while the counter i is less than or equal to the length of the string genomeInstance
            {
                if (genomeInstance[i] != sequence[i]) //if the string genomeInstance starting at i doesn't equal the string of the sequence starting at i. 
                {
                    hamming_distance = hamming_distance + 1; //add 1 to the hamming distance. 
                }
                i = i + 1; //then add 1 to i. 
            }
            similarity_score = (sequence.length() - hamming_distance) / (sequence.length()); //the equation for the sim_score. 
            
            if (similarity_score > bestSimScore) //if current SimilarityScore is greater than the bestSimilarityScore
            {
                bestSimScore = similarity_score; //then replace the bestSimScore with the new score. 
            }
            
            instanceStart = instanceStart + 1; //then add 1 to the instance. 
        } 
        
        while (instanceStart < (genome.length() - sequence.length())); /*end of the "do while" sequence. Do all this stuff while the start of the string is 
        less than the length of the difference of the genome and sequence*/
    }
    return bestSimScore; //return the value for bestSimScore. 
}
int main() //test cases
{ 
    cout <<"test 1: " << findBestSimScore("ATACGC", "ACT") << endl; //should return .6666667 repeating.
    cout << "test 2: " << findBestSimScore("ATTTTTTA", "T") << endl; //should return 1
    cout << "test 3: " << findBestSimScore("ATTTTTTA", "") << endl; //should return 0 due to it being blank.
    
}