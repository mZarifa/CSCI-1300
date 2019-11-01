// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 1 - Problem 3

#include <iostream>
#include <string>
using namespace std;

// algorithm: to compute the hire score based on user inputs for a fox or bunny or sloth. 
void zootopia1300()
{
	int menuInput; //create an integer called menuInput. 
	cout << "Select a numerical option:" << endl;
	cout << "=== menu ===" << endl;
	cout << "1. Fox" << endl;
	cout << "2. Bunny" << endl;
	cout << "3. Sloth" << endl;
	cout << "4. Quit" << endl; // ask the user to input a number corresponding to the options.
	cin >> menuInput; //set the user input to the variable menuInput.
	double strength;
	double speed;
	double agility; //create the variables strength, speed, and agility. 
	
	if (menuInput == 1) //if the user inputs 1
	{
		cout << "Enter agility:" << endl; //ask for the agility
		cin >> agility; //set user input to the agility variable. 
		cout << "Enter strength:" << endl; //ask the user for the strength
		cin >> strength; //set the user input to the strength variable.
		speed = 0; //set the speed to 0 to remove previous values. 
		double hireScore = 1.8 * agility + 2.16 * strength + 3.24 * speed; //equation for hire score.
		cout << "Hire Score: " << hireScore; //output the hire score
		cout << endl;
		zootopia1300(); //restart the program. 
	}
	if (menuInput == 2) 
	{
		double strength;
		double speed;	
		double agility; //create the variables strength, speed, and agility. 
		cout << "Enter agility:" << endl; // ask for the agility
		cin >> agility; //set user input to agility.
		cout << "Enter speed:" << endl; //ask the user for speed
		cin >> speed; //set the user input to speed. 
		strength = 0; //set the strength to 0 to remove previous values. 
		double hireScore = (1.8 * agility) + (2.16 * strength) + (3.24 * speed); //equation for hire score.
		cout << "Hire Score: " << hireScore; //output the hire score
		cout << endl;
		zootopia1300(); //restart the program.
	}
	if (menuInput == 3)
	{
		double strength;
		double speed;
		double agility; //create the variables strength, speed, and agility. 
		cout << "Enter strength:" << endl; //ask the user for the strength
		cin >> strength; //set the user input to the strength
		cout << "Enter speed:" << endl; //ask the user for the speed
		cin >> speed; //set the user input to speed
		agility = 0; //set the agility to 0 to remove any previous values. 
		double hireScore = 1.8 * agility + 2.16 * strength + 3.24 * speed; //equation for hire score.
		cout << "Hire Score: " << hireScore; //output the hire score
		cout << endl;
		zootopia1300(); //restart the program
	}
	if (menuInput == 4) //if the user inputs 4
	{
		return; //end the program
	}
	if (menuInput != 1 && menuInput != 2 && menuInput != 3 && menuInput != 4) //if the user doesnt input 1,2,3 or 4.
	{
		cout << "Invalid input!" << endl; //say "invalid input" and end the program. 
	}
}

int main()
{
	zootopia1300();
}
