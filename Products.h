#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Products 
     
{
    int Price;
    string Name;
    string ExpireDate;
    int id;

public:
    Products();
    

    void setId(int id);
    int getId();

    void setName(string name);
    string getName();
    
    void setPrice(int price);
    int getPrice();

    void setExpireDate(string name);
    string getExpireDate();


};

