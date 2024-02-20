#include "Products.h"
 

Products::Products()
{
}

void Products::setId(int id)
{
	this->id = id;
}

int Products::getId()
{
	return this->id;
}

void Products::setName(string name)
{
	this->Name = name;
}

string Products::getName()
{
	return this->Name;
}

void Products::setPrice(int price)
{
	this->Price = price;
}

int Products::getPrice()
{
	return Price;
}

void Products::setExpireDate(string name)
{
	this->ExpireDate= name;
}

string Products::getExpireDate()
{
	return this->ExpireDate;
}
