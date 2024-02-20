#pragma once
#include "Products.h"
class DairyProducts :
    public Products
{
    int Fat_percent;
public:
    DairyProducts();
    DairyProducts(int percent);
    DairyProducts(const DairyProducts& x);
    void setFatPercent(int percent);
    int getFatPercent();

    DairyProducts& operator=(const DairyProducts& c);
    int operator<(const DairyProducts& c);
    int operator>(const DairyProducts& c);
};

