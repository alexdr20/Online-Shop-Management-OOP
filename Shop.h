#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "IPerson.h"
#include "DairyProducts.h"
#include "MeatProducts.h"
#include <vector>
#include <fstream>
 
class Shop :
    public IPerson 
{
	vector <DairyProducts> dairy;
	vector <MeatProducts> meat;
	int DairyProductsNumber;
	int MeatProductsNumber;
	int idMax;
	bool type;
	
public:
	Shop();
	int getIdMax();
	bool getType() override;
	void printType() override;
	void add_Dairy(DairyProducts product);
	void add_Meat(MeatProducts product);
	void edit(int id);
	void delete_product(int id);
	void saveProductsInFile();
	void waitingCommands();
	~Shop();
};

