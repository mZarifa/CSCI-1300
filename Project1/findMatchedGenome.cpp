// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 6

#include <iostream>
#include <string>
using namespace std; 
// Algorithm: to test how similar a sequence is to a genome1, using the equation: similarity_score = (sequence.length() - hamming_distance) / (sequence.length())
void findMatchedGenome(string genome1, string genome2, string genome3, string sequence)
{
    if (genome1.length() == 0 |  genome2.length() == 0 | genome3.length() == 0 | sequence.length() == 0)
    {
        cout << "Genomes or sequence is empty." << endl;
        return;
    }
    
    if (genome1.length() != genome2.length() | genome1.length() != genome3.length() | genome2.length() != genome3.length())
    {
        cout << "Lengths of genomes are different." << endl;
        return;
    }
    
    double bestSimScore1 = 0;
    double bestSimScore2 = 0;
    double bestSimScore3 = 0;
    
    double findBestSimScore1; //create the code, and create two strings, a genome1 string, and a sequence string. 
    {
        bestSimScore1 = 0; //set the variable bestSimScore to 0. 
        double similarity_score = 0; //create a double, called similarity score, and set it to 0. 

        if (genome1.length() >= sequence.length()) //if the length of the genome1 is greater than or equal to the length of the sequence
        { //and the length of the sequence isn't 0. 
        
            int instanceStart = 0; //create a variable for the start of the instance, and set it to 0. 
            do //now do the following...
            {
                double hamming_distance = 0; //create the hamming distance variable, and set it to 0.
                
                string genome1Instance = genome1.substr(instanceStart, sequence.length()); /*create a string called genome1Instance, and it equals the substring of the genome1 string
                from the start of the instance, to the length of the sequence */
                
                int i = 0; //create a counter variable called i, and set it to 0. 
                
                while (i <= genome1Instance.length()) //while the counter i is less than or equal to the length of the string genome1Instance
                {
                    if (genome1Instance[i] != sequence[i]) //if the string genome1Instance starting at i doesn't equal the string of the sequence starting at i. 
                    {
                        hamming_distance = hamming_distance + 1; //add 1 to the hamming distance. 
                    }
                    i = i + 1; //then add 1 to i. 
                }
                similarity_score = (sequence.length() - hamming_distance) / (sequence.length()); //the equation for the sim_score. 
                
                if (similarity_score > bestSimScore1) //if current SimilarityScore is greater than the bestSimilarityScore
                {
                    bestSimScore1 = similarity_score; //then replace the bestSimScore with the new score. 
                }
            
                instanceStart = instanceStart + 1; //then add 1 to the instance. 
            } 
        
            while (instanceStart <= (genome1.length() - sequence.length())); /*end of the "do while" sequence. Do all this stuff while the start of the string is 
            less than the length of the difference of the genome1 and sequence*/
        }
    }

    double findBestSimScore2; //create the code, and create two strings, a genome2 string, and a sequence string. 
    {
         bestSimScore2 = 0; //set the variable bestSimScore to 0. 
        double similarity_score = 0; //create a double, called similarity score, and set it to 0. 

        if (genome2.length() >= sequence.length()) //if the length of the genome2 is greater than or equal to the length of the sequence
        { //and the length of the sequence isn't 0. 
    
            int instanceStart = 0; //create a variable for the start of the instance, and set it to 0. 
            do //now do the following...
            {
                double hamming_distance = 0; //create the hamming distance variable, and set it to 0.
            
                string genome2Instance = genome2.substr(instanceStart, sequence.length()); /*create a string called genome2Instance, and it equals the substring of the genome2 string
                from the start of the instance, to the length of the sequence */
            
                int i = 0; //create a counter variable called i, and set it to 0. 
                
                while (i <= genome2Instance.length()) //while the counter i is less than or equal to the length of the string genome2Instance
                {
                    if (genome2Instance[i] != sequence[i]) //if the string genome2Instance starting at i doesn't equal the string of the sequence starting at i. 
                    {
                        hamming_distance = hamming_distance + 1; //add 1 to the hamming distance. 
                    }
                    i = i + 1; //then add 1 to i. 
                }
                similarity_score = (sequence.length() - hamming_distance) / (sequence.length()); //the equation for the sim_score. 
                
                if (similarity_score > bestSimScore2) //if current SimilarityScore is greater than the bestSimilarityScore
                {
                    bestSimScore2 = similarity_score; //then replace the bestSimScore with the new score. 
                }
                
                instanceStart = instanceStart + 1; //then add 1 to the instance. 
            } 
            
            while (instanceStart <= (genome2.length() - sequence.length())); /*end of the "do while" sequence. Do all this stuff while the start of the string is 
            less than the length of the difference of the genome2 and sequence*/
        }

    }


    double findBestSimScore3; //create the code, and create two strings, a genome string, and a sequence string. 
    {
         bestSimScore3 = 0; //set the variable bestSimScore to 0. 
        double similarity_score = 0; //create a double, called similarity score, and set it to 0. 

        if (genome3.length() >= sequence.length()) //if the length of the genome is greater than or equal to the length of the sequence
        { //and the length of the sequence isn't 0. 
        
            int instanceStart = 0; //create a variable for the start of the instance, and set it to 0. 
            do //now do the following...
            {
                double hamming_distance = 0; //create the hamming distance variable, and set it to 0.
                
                string genome3Instance = genome3.substr(instanceStart, sequence.length()); /*create a string called genomeInstance, and it equals the substring of the genome string
                from the start of the instance, to the length of the sequence */
            
                int i = 0; //create a counter variable called i, and set it to 0. 
            
                while (i <= genome3Instance.length()) //while the counter i is less than or equal to the length of the string genomeInstance
                {
                    if (genome3Instance[i] != sequence[i]) //if the string genomeInstance starting at i doesn't equal the string of the sequence starting at i. 
                    {
                        hamming_distance = hamming_distance + 1; //add 1 to the hamming distance. 
                    }
                    i = i + 1; //then add 1 to i. 
                }
                similarity_score = (sequence.length() - hamming_distance) / (sequence.length()); //the equation for the sim_score. 
            
                if (similarity_score > bestSimScore3) //if current SimilarityScore is greater than the bestSimilarityScore
                {
                    bestSimScore3 = similarity_score; //then replace the bestSimScore with the new score. 
                }
            
                instanceStart = instanceStart + 1; //then add 1 to the instance. 
            } 
        
            while (instanceStart <= (genome3.length() - sequence.length())); /*end of the "do while" sequence. Do all this stuff while the start of the string is 
            less than the length of the difference of the genome and sequence*/
        }
    }
    if (bestSimScore1 > bestSimScore3 && bestSimScore1 > bestSimScore2)
    {
        cout << "Genome 1 is the best match." << endl;
    }
    else if (bestSimScore3 > bestSimScore2 && bestSimScore3 > bestSimScore1)
    {
        cout << "Genome 3 is the best match." << endl;
    }
    else if (bestSimScore2 > bestSimScore1 && bestSimScore2 > bestSimScore3)
    {
        cout << "Genome 2 is the best match." << endl;
    }
    else if (bestSimScore1 == bestSimScore2 == bestSimScore3)
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    else if (bestSimScore2 == bestSimScore3 && bestSimScore2 > bestSimScore1)
    {
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    else if (bestSimScore1 == bestSimScore3 && bestSimScore1 > bestSimScore2)
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
    }
    else if (bestSimScore1 == bestSimScore2 && bestSimScore1 > bestSimScore3)
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
    }
}

int main() //test cases
{
    findMatchedGenome("ABB", "AAA", "AAC", "AB");
}
