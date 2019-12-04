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


using namespace std;


#ifndef POKEMON_H
#define POKEMON_H

class Pokemon
{
    public:
    Pokemon();
    Pokemon(int, string, int, int, int, int, int, string, string);
    void setPokedexNumber(int);
    void setPokemonName(string);
    void setHP(int);
    void setAttack(int);
    void setDefense(int);
    void setSpeed(int);
    void setMax(int);
    void setType(string);
    void setType2(string);

    int getPokedexNumber();
    string getPokemonName();
    int getHP();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getMax();
    string getType();
    string getType2();
    void getAllStats();


    private:
    int PokedexNumber;
    string PokemonName;
    int HP;
    int Attack;
    int Defense;
    int Speed;
    int Max;
    string Type;
    string Type2;

};

#endif
