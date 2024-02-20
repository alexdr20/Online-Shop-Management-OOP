#include "MeatProducts.h"

MeatProducts::MeatProducts()
{
}

MeatProducts::MeatProducts(int type)
{
	this->type = type;
}

MeatProducts::MeatProducts(const MeatProducts& c)
{
	Products x = c;
	 
	this->setExpireDate(x.getExpireDate());
	this->setId(x.getId());
	this->setName(x.getName());
	this->setPrice(x.getPrice());
	this->type=c.type;
}

void MeatProducts::setType(int type)
{
	this->type = type;
}

int MeatProducts::getType()
{
	return type;
}
MeatProducts& MeatProducts::operator=(const MeatProducts& c)
{
	Products x = c;
	if (this != &c) {
		this->setExpireDate(x.getExpireDate());
		this->setId(x.getId());
		this->setName(x.getName());
		this->setPrice(x.getPrice());
		this->type = c.type;
	}
	return *this;
}

int MeatProducts::operator<(const MeatProducts& c)
{
	Products x = c;
	if (this->getPrice() < x.getPrice())
		return 1;
	return 0;
}

int MeatProducts::operator>(const MeatProducts& c)
{
	Products x = c;
	if (this->getPrice() > x.getPrice())
		return 1;
	return 0;
}
 