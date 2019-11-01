// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 7

#include <iostream>
#include <string>
using namespace std; 

//Algorithm: putting it all together in one giant program with a MENUUUUUUUUUUUUUUUUU. LETS GOOOOOOOOOOOO.

double calcSimScore (string seq1, string seq2) //create two strings, seq1 and seq2
{   
    double hamming_distance = 0; //create a variable called hamming_distance, and set it to 0
    double similarity_score = 0; //create the variable for the similarity score, set it to 0
    double string_length = seq1.length(); //create a variable called string length, and set it to the length of the inputted seq1.
    
    if (seq1 == "" || seq2 == "") //if either sequence is blank
    {
        similarity_score = 0;
    }
    else if (seq1.length() != seq2.length()) //if the length of the two sequences are not the same
    {
        similarity_score = 0;
    }
    else
    {
         for (int i = 0; i < seq1.length(); i++) //create an index i, and for i less than the length of sequence, add 1 to i and do the following
    {
        if (seq1[i] != seq2[i]) //if the letter in position 'i' of the two sequences doesnt match
        {
            hamming_distance++; //add 1 to the hamming distance, then do it again
        }
    }
        similarity_score = ((string_length - hamming_distance) / (string_length)); //calculate the sim score.
    }
    cout << "Similarity score: " << similarity_score << endl;
}



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
        
        while (instanceStart <= (genome.length() - sequence.length())); /*end of the "do while" sequence. Do all this stuff while the start of the string is 
        less than the length of the difference of the genome and sequence*/
    }
    cout << "Best similarity score: " << bestSimScore << endl;
}


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



void showMenu()
{
    int menuInput;
    
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
    cin >> menuInput; //set the user input to the variable showMenu.
    
	if (menuInput == 1) //if the user inputs 1
	{
	    string seq1;
	    string seq2;
		cout << "Enter sequence 1:" << endl;
		cin >> seq1;
		cout << "Enter sequence 2:" << endl;
		cin >> seq2;
		calcSimScore (seq1, seq2);
		showMenu();
	}
	else if (menuInput == 2) 
	{
	    string genome;
	    string sequence;
		cout << "Enter genome:" << endl;
		cin >> genome; 
		cout << "Enter sequence:" << endl; 
		cin >> sequence;
		findBestSimScore (genome, sequence);
		showMenu();
	}
	else if (menuInput == 3)
	{
	    string genome1;
	    string genome2;
	    string genome3;
	    string sequence;
		cout << "Enter genome 1:" << endl;
		cin >> genome1; //set user input to genome1
		cout << "Enter genome 2:" << endl; //ask the user for the genome2
		cin >> genome2; //set the user input to genome2
		cout << "Enter genome 3:" << endl; //ask the user for the genome3
		cin >> genome3; //set the user input to genome3
		cout << "Enter sequence:" << endl; //ask the user for the sequence
		cin >> sequence; //set the user input to the sequence
		findMatchedGenome(genome1, genome2, genome3, sequence);
		showMenu();
	}
	else if (menuInput == 4) //if the user inputs 4
	{
	    cout << "Good bye!";
		return; //end the program
	}
	else
	{
	    cout << "Invalid option." << endl;
	    showMenu();
	}
}


int main()
{
    showMenu();
}

