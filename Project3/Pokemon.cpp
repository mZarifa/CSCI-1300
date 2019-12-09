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
#include "Pokemon.h"
#include "Pokedex.h"

using namespace std;

Pokemon::Pokemon()
{
    PokedexNumber = 0;
    PokemonName = "";
    HP = 0;
    Attack = 0;
    Defense = 0;
    Speed = 0;
    Max = 0;
    Type = "";
    Type2 = "";
}

Pokemon::Pokemon(int input, string input2, int input3, int input4, int input5, int input6, int input7, string input8, string input9)
{
    PokedexNumber = input;
    PokemonName = input2;
    HP = input3;
    Attack = input4;
    Defense = input5;
    Speed = input6;
    Max = input7;
    Type = input8;
    Type2 = input9;
}

void Pokemon::setPokedexNumber(int input)
{
    PokedexNumber = input;
}
void Pokemon::setPokemonName(string input)
{
    PokemonName = input;
}
void Pokemon::setHP(int input)
{
    HP = input; 
}
void Pokemon::setAttack(int input)
{
    Attack = input;  
}
void Pokemon::setDefense(int input)
{
    Defense = input;  
}
void Pokemon::setSpeed(int input)
{
    Speed = input; 
}
void Pokemon::setMax(int input)
{
    Max = input; 
}
void Pokemon::setType(string input)
{
    Type = input;  
}
void Pokemon::setType2(string input)
{
    Type2 = input;
}



int Pokemon::getPokedexNumber()
{
    return PokedexNumber;
}
string Pokemon::getPokemonName()
{
    return PokemonName;
}
int Pokemon::getHP()
{
    return HP;
}
int Pokemon::getAttack()
{
    return Attack;
}
int Pokemon::getDefense()
{
    return Defense;
}
int Pokemon::getSpeed()
{
    return Speed;
}
int Pokemon::getMax()
{
    return Max;
}
string Pokemon::getType()
{
    return Type;
}
string Pokemon::getType2()
{
    return Type2;
}


void Pokemon :: getAllStats()
{
    cout << "Name: " << PokemonName << "\n" << "HP: " << to_string(HP) << "\n" <<
    "Attack: " << to_string(Attack) << " || " << "Defense: " << to_string(Defense) << " || " <<
    "Speed: " << to_string(Speed) << " || " << "Max: " << Max << " || " << "Type: " << Type << " || " << "Type2: " << Type2 << endl;
}
