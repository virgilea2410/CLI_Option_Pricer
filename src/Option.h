/*
 * Option.h
 *
 *  Created on: Jan 11, 2018
 *      Author: virgileamato
 */

#ifndef OPTION_H_
#define OPTION_H_

#include "Stock.h"

class Option
{
	protected:
		Stock udl;
		double strike;
		double tenor;
		string type;
		double rf;

	public:
		Option();
		Option(Option const& a_one_option);
		Option(Stock one_udl);
		Option(Stock* one_udl);
		Option(Stock one_udl, double strike);
		Option(Stock* one_udl, double price);
		Option(Stock one_udl, double strike, double tenor);
		Option(Stock* one_udl, double price, double tenor);
		Option(Stock one_udl, double strike, double tenor, double rf);
		Option(Stock* one_udl, double price, double tenor, double rf);
		Option(Stock one_udl, double strike, double tenor, double rf, string type);
		Option(Stock* one_udl, double strike, double tenor, double rf, string type);
		~Option();

		Stock get_udl() const;
		void set_udl(Stock a_one_udl);

		double get_strike() const;
		void set_strike(double a_strike);

		double get_tenor() const;
		void set_tenor(double a_tenor);

		string get_type() const;
		void set_type(string a_type);

		double get_rf() const;
		void set_rf(double a_rf);
};

bool operator==(Option const& one_option, Option const& two_option);
bool operator!=(Option const& one_option, Option const& two_option);
bool operator>=(Option const& one_option, Option const& two_option);
bool operator<=(Option const& one_option, Option const& two_option);
bool operator>(Option const& one_option, Option const& two_option);
bool operator<(Option const& one_option, Option const& two_option);
ostream& operator<<(ostream& flux, Option const& one_option);


#endif

/* OPTION_H_ */
