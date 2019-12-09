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
#include "Pokemon.cpp"
#include "Pokedex.h"
#include "Pokedex.cpp"
#include "Player.h"
#include "Player.cpp"
#include "Map.h"
#include "Map.cpp"

using namespace std;

int random()
{
    int min = 0;
    int max = 152;
    static bool first = true;
    if (first) 
    {  
      srand(time(NULL)); //first time seeding. 
      first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

string starterMenu;
int starterMenuInt;
string fileName;
string playerName;
string starterName;
Player gameTime;
Pokedex opponentDex("File");
Pokedex masterDex("File");
Pokemon playerPoke1;
Pokemon battleMon;
int playerSize;

int dupeCheck;
int battleCount;

string inputvalue;
Pokemon tempBattle;
int statholder;
int playerSelect;
int holder = random();

int startUpMenu()
{
    cout << "Enter a name" << endl;
    getline(cin, playerName);
    {
        while (starterMenu != "4")
        {
            cout << "Welcome to the wonderful world of Pokemon " << playerName << "!" << endl;
            cout << "Choose your starter Pokemon!" << endl;
            cout << "1. Bulbasaur" << endl;
            cout << "2. Squirtle" << endl;
            cout << "3. Charmander" << endl;
            cout << "4. Quit" << endl;
            getline(cin, starterMenu);
            if (starterMenu != "1" && starterMenu != "2" && starterMenu != "3" && starterMenu != "4")
            {
                cout << "invalid input! Please enter only the numbers 1, 2, 3, or 4" << endl;
            }
            else
            {
                starterMenuInt = stoi(starterMenu);
                starterMenu = starterMenuInt;
            }

            switch(starterMenuInt)
            {
                case 1:
                {
                    starterName = "Bulbasaur";
                    cout << "You have chosen " << starterName << "!" << " Your adventure begins here!" << endl;
                    playerSize++;
                    return 0;
                }
                case 2:
                {
                    starterName = "Squirtle";
                    cout << "You have chosen " << starterName << "!" << " Your adventure begins here!" << endl;
                    playerSize++;
                    return 0;
                }
                case 3:
                {
                    starterName = "Charmander";
                    cout << "You have chosen " << starterName << "!" << " Your adventure begins here!" << endl;
                    playerSize++;
                    return 0; 
                }
                case 4:
                {
                    cout << "Goodbye!" << endl;
                    return 1;
                }
                default:
                {
                    cout << "Incorrect menu input! Please enter a number!" << endl;
                    break;
                }
            }
        }
    }
}


int playerBattleSetup()
{
    string typed;
    gameTime.outputAllPlayerPokemon();
    cout << "Which Pokemon will you send out? Input the name of the Pokemon!" << endl;
    getline(cin, typed);
    for(int i = 0; i <= playerSize; i++)
    {
        int playerSelect = i;
        Pokemon check;
        check = gameTime.getPlayerPokemonAt(playerSelect);
        string nameCheck;
        nameCheck = check.getPokemonName();
        if(nameCheck == typed)
        {
            tempBattle = gameTime.getPlayerPokemonAt(playerSelect);
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int battleMenu()
{
    int result;
    if(tempBattle.getHP() == 0)
    {
        Pokemon Swap;
        Swap = gameTime.getPlayerPokemonAt(playerSize);
        tempBattle = Swap;
        if(Swap.getPokemonName() == "")
        {
            return 3;
        }
    }
    else
    {
        cout << "------------------------------------------------------------------------------" << endl;
        cout << playerName << " sent out " << tempBattle.getPokemonName() << "!" << endl;
        cout << endl;
        cout << "What will you do? Type the response." << endl;
        cout << "1. Attack." << endl;
        cout << "2. Switch Pokemon." << endl;
        cout << "3. Check my opponents Pokemon." << endl;
        cout << "4. Surrender." << endl;
        cout << "------------------------------------------------------------------------------" << endl;
    }
    string battleInput;
    string battleInputInt;
    getline(cin, battleInput);
    int playerMonHP = tempBattle.getHP();
    double oppDefenseRatio = tempBattle.getAttack()/battleMon.getDefense();
    int playerMonDamage = (tempBattle.getAttack() * oppDefenseRatio);
        
    int oppMonHP = battleMon.getHP();
    double playerDefenseRatio = battleMon.getAttack()/tempBattle.getDefense();
    double oppMonDamage = (battleMon.getAttack() * playerDefenseRatio);


        int battleMenuInt;
        if(battleInput == "Attack")
        {
            battleMenuInt = 1;
        }
        else if(battleInput == "Switch pokemon")
        {
            battleMenuInt = 2;
        }
        else if(battleInput == "Check my opponents Pokemon")
        {
            battleMenuInt = 3;
        }
        else if(battleInput == "Surrender")
        {
            battleMenuInt = 4;
        }
        else
        {
            cout << "Invalid input!" << endl;
            battleMenu();
            
        }
        switch(battleMenuInt)
        {
            
            case 1:
            {
                if(tempBattle.getSpeed() >= battleMon.getSpeed())
                {
                    cout << "You attack first! " << tempBattle.getPokemonName() << " deals " << playerMonDamage << "!" << endl;
                    battleMon.setHP(battleMon.getHP()-playerMonDamage);
                    if(battleMon.getHP() < 0)
                    {
                        battleMon.setHP(0);
                    }
                    cout << battleMon.getPokemonName() << " deals " << oppMonDamage << " damage!" << endl;
                    tempBattle.setHP(tempBattle.getHP() - oppMonDamage);
                    if(tempBattle.getHP() < 0)
                    {
                        tempBattle.setHP(0);
                    }
                    else if(battleMon.getHP() < 0)
                    {
                        tempBattle.setHP(0);
                    }
                }
                else
                {
                    cout << "You will attack second! " << battleMon.getPokemonName() << " deals " << oppMonDamage << " damage!" << endl;
                    tempBattle.setHP(tempBattle.getHP() - oppMonDamage);
                    cout << tempBattle.getPokemonName() << " deals " << playerMonDamage << " damage!" << endl;
                    cout << tempBattle.getPokemonName() << " now has " << tempBattle.getHP() << " health left." << endl;
                    if(tempBattle.getHP() < 0)
                    {
                        tempBattle.setHP(0);
                    }
                    if(battleMon.getHP() < 0)
                    {
                        battleMon.setHP(0);
                    }
                    cout << battleMon.getPokemonName() << " now has " << battleMon.getHP() << " health left." << endl;
                }
                if(battleMon.getHP() == 0)
                {
                    cout << battleMon.getPokemonName() << " fainted!" << endl;
                    result = 1;
                }
                else if(tempBattle.getHP() == 0 && battleMon.getHP() >= 1)
                {
                    cout << tempBattle.getPokemonName() << " fainted!" << endl;
                    return 3;
                    gameTime.setPlayerPokemon(playerSelect, tempBattle);
                    for(int i = 0; i < playerSize; i++)
                    {
                        if(gameTime.getPlayerPokemonAt(i).getHP() != 0 || gameTime.getPlayerPokemonAt(i).getHP() < 0)
                        {
                            result = 2;
                        }
                        else
                        {
                            result = 3;
                        } 
                    }
                }
                else
                {
                    result = 1;
                }
                
                return result; 
            }
            case 2:
            {
                cout << "Which pokemon will you sub in?" << endl;
                result = 4;
                return result;
            }
            case 3:
            {
                battleMon.getAllStats();
                result = 4;
                return result;
            }
            case 4:
            {
                cout << "Goodbye!" << endl;
                result = 5;
                return result;
            }
    }
}

void oppBattleSetup()
{
    opponentDex.readPokedex("oppositionPokemon.txt");
    if (dupeCheck == holder)
    {
        holder = random();
    }
    else
    {
        battleMon = opponentDex.getAllPokeStatsByInt(holder);
        dupeCheck = holder;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "The opposing trainer sent out: " << battleMon.getPokemonName() << "!" << endl;
        battleMon.getAllStats();
        cout << "Let the battle begin!" << endl;
        cout << "------------------------------------------------------" << endl;
    }
}

void initilizer()
{
    masterDex.readPokedex("pokemon.txt");
    Pokemon Dud(masterDex.getAllPokeStats(starterName));
    playerPoke1 = Dud;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Here are your starter Pokemon's stats!" << endl;
    playerPoke1.getAllStats();
    gameTime.addPlayerPokemon(playerPoke1);
}
int main()
{
    int checker;
    checker = startUpMenu();
    if (checker == 1)
    {
        return 0;
    }
    initilizer();
    oppBattleSetup();
    checker = playerBattleSetup();
    if (checker == 1)
    {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Invalid input! Try again!" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        playerBattleSetup();
    }
    int check2;
    check2 = battleMenu();
        if (check2 == 0)
        {
            battleMenu();
        }
        else if (check2 == 1)
        {
            cout << "The opponents Pokemon fainted!" << endl;
            battleCount++;
            cout << "All your Pokemon have leveled up!" << endl;
            for(int i = 0; i < playerSize; i++)
                {
                    Pokemon temp = masterDex.getAllPokeStatsByInt(i);
                    temp = gameTime.getPlayerPokemonAt(i);
                    temp.setAttack(temp.getAttack() + (temp.getMax()/4));
                    temp.setDefense(temp.getDefense() + (temp.getMax()/4));
                    temp.setSpeed(temp.getSpeed() + (temp.getMax()/4));
                    gameTime.setPlayerPokemon(i, temp);
                }
            cout << "You have won " << battleCount << " battles!" <<endl;
            string temp = battleMon.getPokemonName();
            gameTime.setPlayerPokemon(playerSize, masterDex.getAllPokeStats(temp));
            playerSize++;
            cout << "You won the opponents Pokemon!" << endl;
            if(battleCount %6 == 0)
            {
                cout << "We have healed your Pokemon!" << endl;
                for(int i = 0; i < playerSize; i++)
                {
                    Pokemon healthHold = gameTime.getPlayerPokemonAt(i);
                    Pokemon temp = masterDex.getAllPokeStats(healthHold.getPokemonName());
                    int maxHealth = temp.getHP();
                    healthHold.setHP(maxHealth);
                    gameTime.setPlayerPokemon(i, healthHold);
                }
            }
            cout << "Here comes another challenger!" << endl;
            battleMenu();
        }
        else if(check2 == 2)
        {
            battleMenu();
        }
        else if (check2 == 3)
        {
            cout << "Good game! You survived " << battleCount << " battles!" << endl;
            cout << "Thanks for playing!" << endl;
            return 0;
        }
}

