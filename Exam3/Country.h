#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#ifndef COUNTRY_H
#define COUNTRY_H

class Country
{
    public:
    Country();
    int LoadCountry(string);
    int SearchForCountry(string);
    string GetCapital(string);

    private:
    string countries[50];
    string capitals[50];

};
#endif