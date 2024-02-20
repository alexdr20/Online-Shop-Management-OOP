#pragma once
#include "Products.h"
class MeatProducts :
    public Products
{
    int type;
public:
    MeatProducts();
    MeatProducts(int type);
    MeatProducts(const MeatProducts& x);
    void setType(int type);
    int getType();

    MeatProducts& operator=(const MeatProducts& c);
    int operator<(const MeatProducts& c);
    int operator>(const MeatProducts& c);
};

