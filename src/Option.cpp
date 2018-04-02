/*
 * Option.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: virgileamato
 */

#include "Option.h"

Option::Option()
{
	this->type = Constants::CALL;
	//this->udl = Stock::Stock("APPLE", 100, 0.02);
	this->udl = *(new Stock("APPLE", 100, 0.02));
	this->strike = 100;
	this->tenor = 1;
	this-> rf = 0.02;
}

Option::Option(Option const& a_one_option)
{
	this->type = a_one_option.get_type();
	this->udl = a_one_option.get_udl();
	this->strike = a_one_option.get_strike();
	this->tenor = a_one_option.get_tenor();
	this->rf = a_one_option.get_rf();
}

Option::Option(Stock my_udl)
{
	this->type = Constants::CALL;
	this->udl = my_udl;
	this->strike = my_udl.get_price();
	this->tenor = 1;
	this->rf = 0.02;
}

Option::Option(Stock* my_udl)
{
	this->type = Constants::CALL;
	this->udl = *my_udl;
	this->strike = my_udl->get_price();
	this->tenor = 1;
	this->rf = 0.02;
}

Option::Option(Stock my_udl, double one_strike)
{
	this->type = Constants::CALL;
	this->udl = my_udl;
	this->strike = one_strike;
	this->tenor = 1;
	this->rf = 0.02;
}

Option::Option(Stock* my_udl, double one_strike)
{
	this->type = Constants::CALL;
	this->udl = *my_udl;
	this->strike = one_strike;
	this->tenor = 1;
	this->rf = 0.02;
}

Option::Option(Stock my_udl, double one_strike, double tenor)
{
	this->type = Constants::CALL;
	this->udl = my_udl;
	this->strike = one_strike;
	this->tenor = tenor;
	this->rf = 0.02;
}

Option::Option(Stock* my_udl, double one_strike, double tenor)
{
	this->type = Constants::CALL;
	this->udl = *my_udl;
	this->strike = one_strike;
	this->tenor = tenor;
	this->rf = 0.02;
}

Option::Option(Stock my_udl, double one_strike, double tenor, double rf)
{
	this->type = type;
	this->udl = my_udl;
	this->strike = one_strike;
	this->tenor = tenor;
	this->rf = rf;
}

Option::Option(Stock* my_udl, double one_strike, double tenor, double rf)
{
	this->udl = *my_udl;
	this->strike = one_strike;
	this->tenor = tenor;
	this->rf = 0.02;
}

Option::Option(Stock my_udl, double one_strike, double tenor, double rf, string type)
{
	this->type = type;
	this->udl = my_udl;
	this->strike = one_strike;
	this->tenor = tenor;
	this->rf = rf;
}

Option::Option(Stock* one_udl, double strike, double tenor, double rf, string type)
{
	this->type = type;
	this->udl = *one_udl;
	this->strike = strike;
	this->tenor = tenor;
	this->rf = rf;
}

Option::~Option()
{

}

Stock Option::get_udl() const
{
	return this->udl;
}

void Option::set_udl(Stock a_one_stock)
{
	this->udl = a_one_stock;
}

double Option::get_strike() const
{
	return this->strike;
}

void Option::set_strike(double a_strike)
{
	this->strike = a_strike;
}

double Option::get_tenor() const
{
	return this->tenor;
}

void Option::set_tenor(double a_tenor)
{
	this->tenor = a_tenor;
}

string Option::get_type() const
{
	return this->type;
}

void Option::set_type(string a_type)
{
	this->type = a_type;
}

double Option::get_rf() const
{
	return this->rf;
}

void Option::set_rf(double a_rf)
{
	this->rf = a_rf;
}

bool operator==(Option const& one_option, Option const& two_option)
{
	if (one_option.get_type() == two_option.get_type() && one_option.get_udl() == two_option.get_udl() && one_option.get_strike() == two_option.get_strike() && one_option.get_tenor() == two_option.get_tenor() && one_option.get_rf() == two_option.get_rf())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(Option const& one_option, Option const& two_option)
{
	if (not(one_option.get_type() == two_option.get_type() && one_option.get_udl() == two_option.get_udl() && one_option.get_strike() == two_option.get_strike() && one_option.get_tenor() == two_option.get_tenor() && one_option.get_rf() == two_option.get_rf()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(Option const& one_option, Option const& two_option)
{
	if (true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<=(Option const& one_option, Option const& two_option)
{
	if (true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(Option const& one_option, Option const& two_option)
{
	if (true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(Option const& one_option, Option const& two_option)
{
	if (true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& flux, Option const& one_option)
{
	flux << "Option Type : " << one_option.get_type() << endl;
	flux << "Option Underlying : " << endl << one_option.get_udl() << endl;
	flux << "Option Strike : " << one_option.get_strike() << endl;
	flux << "Option Spot : " << one_option.get_udl().get_price() << endl;
	flux << "Option Maturity : " << one_option.get_tenor() << endl;
	flux << "Option Risk Free Rate : " << one_option.get_rf() << endl;

	return flux;

}

