#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;


#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack
{
    public:
    RaceTrack();
    RaceTrack(string);
    bool addCar(double, string);
    double calcAvgSpeed();
    int countAvailable(double);
    int countAvailableModels(string);

    private:
    string name;
    vector <string> models;
    vector <double> speeds;

};
#endif