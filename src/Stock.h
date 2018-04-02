/*
 * Stock.h
 *
 *  Created on: Jan 11, 2018
 *      Author: virgileamato
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>
#include <string>
#include "Constants.h"

using namespace std;

class Stock
{
	protected:
		string name;
		double price;
		double vol;

	public:
		Stock();
		Stock(Stock const& one_stock);
		Stock(string name);
		Stock(string name, double price);
		Stock(string name, double price, double vol);
		~Stock();

		string get_name() const;
		void set_name(string a_name);

		double get_price() const;
		void set_price(double a_price);

		double get_vol() const;
		void set_vol(double a_vol);
};

bool operator==(Stock const& one_stock, Stock const& two_stock);
bool operator!=(Stock const& one_stock, Stock const& two_stock);
bool operator>=(Stock const& one_stock, Stock const& two_stock);
bool operator<=(Stock const& one_stock, Stock const& two_stock);
bool operator>(Stock const& one_stock, Stock const& two_stock);
bool operator<(Stock const& one_stock, Stock const& two_stock);
ostream& operator<<(ostream& flux, Stock const& one_stock);

#endif

/* STOCK_H_ */
