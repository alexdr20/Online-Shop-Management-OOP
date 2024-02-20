#pragma once
#pragma once
#include "IPerson.h"
#include <fstream>
#include <string>
#include <vector>


class Client : public IPerson
{
	bool type;
	vector <string> basket;
	int basketProducts;
	int finalPrice;
public:
	Client();

	bool getType() override;
	void printType() override;
	void printProducts();
	void addToBasket(int id, int number);
	void removeFromBasket(int elem);
	void sendOrder();
	void preview();
	~Client();
};