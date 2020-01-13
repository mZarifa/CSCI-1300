#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include "book.h"

using namespace std;

Book::Book()
{
    title = "";
    sales = 0.0;
}
Book::Book(string var1, double var2)
{
    title = var1;
    sales = var2;
}
void Book::setTitle(string input)
{
    title = input;
}
void Book::setSales(double input)
{
    sales = input;
}
string Book:: getTitle()
{
    return title;
}
double Book :: getSales()
{
    return sales;
}
int Book :: sold(double input)
{
    int sold = sales/input;
    return sold;
}

