#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book
{
    public:
    Book();
    Book(string, double);
    void setTitle(string);
    void setSales(double);
    string getTitle();
    double getSales();
    int sold(double);

    private:
    string title;
    double sales;

};
#endif