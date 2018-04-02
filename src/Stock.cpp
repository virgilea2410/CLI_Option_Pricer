/*
 * Stock.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: virgileamato
 */


#include "Stock.h"


Stock::Stock()
{
	this->name 	= "GOOGLE";
	this->price 	= 100;
	this->vol 	= 0.02;
}

Stock::Stock(Stock const& one_stock)
{
	//this->name = one_stock.get_name();
	//this->price = one_stock.get_price();
	//this->vol = one_stock.get_vol();

	name 	= one_stock.get_name();
	price 	= one_stock.get_price();
	vol 		= one_stock.get_vol();
}

Stock::Stock(string a_name)
{
	this->name 	= a_name;
	this->price	= 100;
	this->vol 	=	0.02;
}

Stock::Stock(string a_name, double a_price)
{
	this->name 	= a_name;
	this->price 	= a_price;
	this->vol 	= 0.02;
}

Stock::Stock(string a_name, double a_price, double a_vol)
{
	this->name 	= a_name;
	this->price 	= a_price;
	this->vol 	= a_vol;
}

Stock::~Stock()
{

}

string Stock::get_name() const
{
	return this->name;
}

double Stock::get_price() const
{
	return this->price;
}

double Stock::get_vol() const
{
	return this->vol;
}

void Stock::set_name(string a_name)
{
	this->name = a_name;
}

void Stock::set_price(double a_price)
{
	this->price = a_price;
}

void Stock::set_vol(double a_vol)
{
	this->vol = a_vol;
}

bool operator==(Stock const& one_stock, Stock const& two_stock)
{
	if (one_stock.get_name() == two_stock.get_name() && one_stock.get_vol() == two_stock.get_vol() && one_stock.get_price() == two_stock.get_price())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(Stock const& one_stock, Stock const& two_stock)
{
	if (not(one_stock.get_name() == two_stock.get_name() && one_stock.get_vol() == two_stock.get_vol() && one_stock.get_price() == two_stock.get_price()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(Stock const& one_stock, Stock const& two_stock)
{
	if (one_stock.get_price() >= two_stock.get_price())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<=(Stock const& one_stock, Stock const& two_stock)
{
	if (one_stock.get_price() <= two_stock.get_price())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(Stock const& one_stock, Stock const& two_stock)
{
	if (one_stock.get_price() > two_stock.get_price())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(Stock const& one_stock, Stock const& two_stock)
{
	if (one_stock.get_price() < two_stock.get_price())
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& flux, Stock const& one_stock)
{
	flux << "Stock Name : " << one_stock.get_name() << endl;
	flux << "Stock Volatility : " << one_stock.get_vol() << endl;
	flux << "Stock Price : " << one_stock.get_price() << endl;

	return flux;
}


