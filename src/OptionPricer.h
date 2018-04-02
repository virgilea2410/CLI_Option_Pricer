/*
 * OptionPricer.h
 *
 *  Created on: Jan 12, 2018
 *      Author: virgileamato
 */


#ifndef OPTIONPRICER_H_
#define OPTIONPRICER_H_


#include <algorithm>
#include <random>
#include "Pricer.h"
#include "Stock.h"
#include "Option.h"
#include "Tools.h"
#include "Constants.h"


class OptionPricer : Pricer
{
	protected:
		Stock udl;
		Option option;
		double strike;
		double spot;
		double tenor;
		double delta;
		double vega;
		double gamma;

	public:
		OptionPricer();
		OptionPricer(OptionPricer const& one_pricer);
		OptionPricer(Stock one_udl);
		OptionPricer(Stock one_udl, double a_strike);
		OptionPricer(Stock one_udl, double a_strike, double a_tenor);
		OptionPricer(Option a_one_option);
		OptionPricer(string one_file_option);
		OptionPricer(ifstream& one_file_option);
		~OptionPricer();

		double get_price(string method);

		double get_mc_price(int nb_simul, int step);
		double get_bs_price();
		double get_binom_price(double step_p_year);

		void exportPricing(string method, double price);
		bool checkResultFile();

		Stock get_udl() const;
		void set_udl(Stock a_one_stock);

		Option get_option() const;
		void set_option(Option a_one_option);

		double get_strike() const;
		void set_strike(double a_one_strike);

		double get_spot() const;
		void set_spot(double a_one_spot);

		double get_tenor() const;
		void set_tenor(double a_one_tenor);

		double get_vega() const;
		double get_delta() const;
		double get_gamma() const;
};

ostream& operator<<(ostream& flux, OptionPricer one_option_pricer);


#endif /* OPTIONPRICER_H_ */
