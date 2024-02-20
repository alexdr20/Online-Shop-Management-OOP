#include "DairyProducts.h"

DairyProducts::DairyProducts()
{
}

DairyProducts::DairyProducts(int percent)
{
	this->Fat_percent = percent;
}

DairyProducts::DairyProducts(const DairyProducts&c)
{
	Products x = c;
	this->Fat_percent = c.Fat_percent;
	this->setExpireDate(x.getExpireDate());
	this->setId(x.getId());
	this->setName(x.getName());
	this->setPrice(x.getPrice());
}

void DairyProducts::setFatPercent(int percent)
{
	this->Fat_percent = percent;
}

int DairyProducts::getFatPercent()
{
	return this->Fat_percent;
}

DairyProducts& DairyProducts::operator=(const DairyProducts& c)
{
	Products x = c;
	
	if (this != &c)
	{
		this->Fat_percent = c.Fat_percent;
		this->setExpireDate(x.getExpireDate());
		this->setId(x.getId());
		this->setName(x.getName());
		this->setPrice(x.getPrice());
	}
	return *this;
}

int DairyProducts::operator<(const DairyProducts& c)
{
	Products x = c;
	if(this->getPrice()<x.getPrice())
		return 1;
	return 0;
}

int DairyProducts::operator>(const DairyProducts& c)
{
	Products x = c;
	if (this->getPrice() > x.getPrice())
		return 1;
	return 0;
}
