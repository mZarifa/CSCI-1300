// CS1300 Fall 2019
// Author: Matthew Zarifa
// Recitation: 112 - Behera
// Project 3

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "Player.h"
#include "Pokemon.h"
#include "Pokedex.h"

using namespace std;

void split(string line, char deliminator, string words[], int arrSize) //create the variables
{
    
    string temp = ""; //create a string that is blank.
    int arrayposition = 0; //create a position holder.
    
    for (int i = 0; i < line.length(); i++) //for i less than the length of the line, do the following
    {
        if( line[i] != deliminator) //if the character in the line i isn't the deliminator
        {
            temp = temp + line[i]; //set the temp string to whatever was in it plus that character
        }
        else
        {
            if (i != 0 && i != (line.length() - 1)) // if i isn't 0, and isn't 1 less than the length of the string...
            words[arrayposition] = temp; //set the array of words at the given position to the temp string
            temp = ""; //set the temp string to blank
            arrayposition++; //add 1 to the arrayposition
            
            int check = i + 1; //create a match check, at i + 1
            if (line[check] == deliminator) //if the line at the checker is the deliminator
            {
                i++; //add 1 to i.
            }
            else
            {
                if (i == line.length() - 1) // if i is the same length as the inputted line - 1.
                {
                    i++; //add 1 to i.
                }
            }
        }
    }
    words[arrayposition] = temp; //set the string 'words' to whatever is in temp at the moment. 
}

Pokedex::Pokedex() //function for reading the master dex. 
{
    string line = ""; //create a string called line, and make it blank.
    string tempArray[8]; //create a temp array string with size of 3 for the values
    
    ifstream in_file;
    in_file.open("pokemon.txt"); //open the file
    
    if(in_file.is_open()) //if its open
    {
        while (getline(in_file, line)) //while its open
        {
            split(line, ',', tempArray, 9); //run the split function
            Pokemon newPokemon;
            newPokemon.setPokedexNumber(stod(tempArray[0])); //set the new Players to tempArray[0].
            newPokemon.setPokemonName(tempArray[1]);
            newPokemon.setHP(stod(tempArray[2]));
            newPokemon.setAttack(stod(tempArray[3]));
            newPokemon.setDefense(stod(tempArray[4]));
            newPokemon.setSpeed(stod(tempArray[5]));
            newPokemon.setMax(stod(tempArray[6]));
            newPokemon.setType(tempArray[7]);
            newPokemon.setType2(tempArray[8]);
            pokemons.push_back(newPokemon);
        }
        in_file.close(); //close the file.
    }
}

Pokedex::Pokedex(string input) //function for reading the roster.
{
    trainerName = input;

}

void Pokedex::readPokedex(string fileName) //function for reading the roster.
{
    string line = ""; //create a string called line, and make it blank.
    string tempArray[8]; //create a temp array string with size of 3 for the values
    
    ifstream in_file;
    in_file.open(fileName); //open the file
    
    if(in_file.is_open()) //if its open
    {
        while (getline(in_file, line)) //while its open
        {
            split(line, ',', tempArray, 8); //run the split function
            Pokemon newPokemon;
            newPokemon.setPokedexNumber(stoi(tempArray[0])); //set the new Players to tempArray[0].
            newPokemon.setPokemonName(tempArray[1]);
            newPokemon.setHP(stoi(tempArray[2]));
            newPokemon.setAttack(stoi(tempArray[3]));
            newPokemon.setDefense(stoi(tempArray[4]));
            newPokemon.setSpeed(stoi(tempArray[5]));
            newPokemon.setMax(stoi(tempArray[6]));
            newPokemon.setType(tempArray[7]);
            newPokemon.setType2(tempArray[8]);
            pokemons.push_back(newPokemon);
        }
        in_file.close(); //close the file.
    }
}
string Pokedex::getPokeName(string input) //function to get the players names
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
            return pokemons[index].getPokemonName();
        }
    }
    return "NULL";
}
int Pokedex::getPokeNumber(string input) //function to get the players names
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if (index >= 0 && index < pokemons.size()) //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getPokedexNumber(); //get the name at the inputted int i
    }
    else
    {
        return -1; //else return error because they're outside the range of 0 and max players. 
    }
}

int Pokedex::getPokeAttack(string input) //function to get the points.
{
    int index = 1;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < pokemons.size())  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getAttack(); //get the player at array position i's points.
    }
    else
    {
        return -1; //else return -1
    }
}

int Pokedex::getPokeDefense(string input) //function to get the points.
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < pokemons.size())  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getDefense(); //get the player at array position i's points.
    }
    else
    {
        return -1; //else return -1
    }
}
int Pokedex::getPokeHP(string input) //function to get the points.
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < pokemons.size())  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getHP(); //get the player at array position i's points.
    }
    else
    {
        return -1; //else return -1
    }
}
int Pokedex::getPokeMax(string input) //function to get the points.
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < pokemons.size())  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getMax(); //get the player at array position i's points.
    }
    else
    {
        return -1; //else return -1
    }
}
int Pokedex::getPokeSpeed(string input)//function to get the points.
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < pokemons.size())  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getSpeed(); //get the player at array position i's points.
    }
    else
    {
        return -1; //else return -1
    }
}
string Pokedex::getPokeType(string input) //function to get the points.
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < 152)  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getType(); //get the player at array position i's points.
    }
    else
    {
        return "NULL"; //else return -1
    }
}
string Pokedex::getPokeType2(string input) //function to get the points.
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    if(index >= 0 && index < 152)  //if i is greater than/equal to 0, but less than the fixed player size
    {
        return pokemons[index].getType2(); //get the player at array position i's points.
    }
    else
    {
        return "NULL"; //else return -1
    }
}
Pokemon Pokedex :: getAllPokeStats(string input)
{
    int index = 0;
    for (int i = 0; i < PokedexSize; i++)
    {
        if (input == pokemons[i].getPokemonName())
        {
            index = i;
        }
    }
    return pokemons[index];
}
Pokemon Pokedex :: getAllPokeStatsByInt(int input)
{
    if ((input - 1) < PokedexSize)
    {
        return pokemons[input];
    }
}
