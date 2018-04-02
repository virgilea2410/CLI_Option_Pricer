/*
 * OptionPricer.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: virgileamato
 */


#include "OptionPricer.h"


OptionPricer::OptionPricer()
{
	this->udl 		= *(new Stock("APPLE", 100, 0.02));
	this->option 	= *(new Option(udl));
	//this->set_methods("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
	//this->set_methods("src/txt/methods.txt");
	this->set_methods(Constants::PATH2METHODS);
	this->strike 	= 100;
	this->spot 		= this->udl.get_price();
	this->tenor 		= 1;
	this->delta 		= 0;
	this->vega 		= 0;
	this->gamma 		= 0;
}

OptionPricer::OptionPricer(OptionPricer const& a_one_pricer)
{
	this->option 	= a_one_pricer.get_option();
	this->udl 		= a_one_pricer.get_udl();
	this->set_methods(a_one_pricer.get_methods());
	this->strike 	= a_one_pricer.get_strike();
	this->spot 		= a_one_pricer.get_spot();
	this->tenor 		= a_one_pricer.get_tenor();
	this->delta 		= 0;
	this->vega 		= 0;
	this->gamma 		= 0;
}

OptionPricer::OptionPricer(Stock a_one_stock)
{
	this->option 	= *(new Option(a_one_stock));
	this->udl 		= a_one_stock;
	//this->set_methods("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
	//this->set_methods("src/txt/methods.txt");
	this->set_methods(Constants::PATH2METHODS);
	this->strike 	= this->udl.get_price();
	this->spot 		= this->udl.get_price();
	this->tenor 		= 1;
	this->delta 		= 0;
	this->vega 		= 0;
	this->gamma 		= 0;
}

OptionPricer::OptionPricer(Stock a_one_stock, double a_strike)
{
	this->option 	= *(new Option(a_one_stock, a_strike, 1));
	this->udl 		= a_one_stock;
	//this->set_methods("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
	//this->set_methods("src/txt/methods.txt");
	this->set_methods(Constants::PATH2METHODS);
	this->strike 	= a_strike;
	this->spot 		= this->udl.get_price();
	this->tenor 		= 1;
	this->delta 		= 0;
	this->vega 		= 0;
	this->gamma 		= 0;
}

OptionPricer::OptionPricer(Stock a_one_stock, double a_strike, double a_tenor)
{
	this->option 	= *(new Option(a_one_stock, a_strike, a_tenor));
	this->udl 		= a_one_stock;
	//this->set_methods("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
	//this->set_methods("src/txt/methods.txt");
	this->set_methods(Constants::PATH2METHODS);
	this->strike 	= a_strike;
	this->spot 		= this->udl.get_price();
	this->tenor 		= a_tenor;
	this->delta 		= 0;
	this->vega 		= 0;
	this->gamma 		= 0;
}

OptionPricer::OptionPricer(Option a_one_option)
{
	this->option		= a_one_option;
	this->udl 		= a_one_option.get_udl();
	//this->set_methods("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
	//this->set_methods("src/txt/methods.txt");
	this->set_methods(Constants::PATH2METHODS);
	this->strike 	= a_one_option.get_strike();
	this->spot 		= a_one_option.get_udl().get_price();
	this->tenor 		= a_one_option.get_tenor();
	this->delta 		= 0;
	this->vega 		= 0;
	this->gamma 		= 0;
}

OptionPricer::OptionPricer(string one_option_file)
{
	ifstream one_file;
	one_file.open(one_option_file);
	string one_line;
	vector<string> inputs;

	if (one_file.is_open())
	{
		while(one_file.eof() != true)
		{
			getline(one_file, one_line, '/');
			inputs.push_back(one_line);
		}
	}
	else
	{
		cout << "wrong file path" << endl;
	}

	string type = inputs[1];
	string name = inputs[2];
	double spot = stod(inputs[3]);
	double vol = stod(inputs[4]);
	double strike = stod(inputs[5]);
	double tenor = stod(inputs[6]);

	this->delta = 0;
	this->vega = 0;
	this->gamma = 0;
	this->tenor = tenor;
	this->udl = *(new Stock(name, spot, vol));
	this->option = *(new Option(this->udl, strike, this->tenor, 0.02, type));
	this->strike = strike;
	this->spot = spot;

	one_file.close();
}

OptionPricer::OptionPricer(ifstream& one_file)
{
	string one_line;
	vector<string> inputs;

	if (one_file.is_open())
	{
		while(one_file.eof() != true)
		{
			getline(one_file, one_line, '/');
			inputs.push_back(one_line);
		}
	}
	else
	{
		cout << "wrong file path" << endl;
	}

	string type = inputs[1];
	string name = inputs[2];
	double spot = stod(inputs[3]);
	double vol = stod(inputs[4]);
	double strike = stod(inputs[5]);
	double tenor = stod(inputs[6]);

	this->delta = 0;
	this->vega = 0;
	this->gamma = 0;
	this->tenor = tenor;
	this->udl = *(new Stock(name, spot, vol));
	this->option = *(new Option(this->udl, strike, this->tenor, 0.02, type));
	this->strike = strike;
	this->spot = spot;
}

OptionPricer::~OptionPricer()
{
}

double OptionPricer::get_price(string a_method)
{
	//
	// Get the price from specified a_method method
	//

	if (a_method == Constants::BSM)
	{
		return this->get_bs_price();
	}
	else if (a_method == Constants::MC)
	{
		return this->get_mc_price(500,365);
	}
	else if (a_method == Constants::BINOMIAL)
	{
		return this->get_binom_price(1000);
	}
	else
	{
		cout << "Méthode " << a_method << " non reconnue" << endl;
	}

	return 0;
}

double OptionPricer::get_bs_price()
{
	//
	// Return the Black & Scholes price of an option
	//

	double vol 			= this->udl.get_vol();
	double strike 		= this->option.get_strike();
	double spot 			= this->udl.get_price();
	double mat 			= this->tenor;
	double rf 			= this->option.get_rf();
	double price 		= 0.00;

	double d1 			= 1/(vol*sqrt(mat))*(log(spot/strike)+(rf+1/2*pow(vol,2))*mat);
	double d2 			= d1 - vol * sqrt(mat);

	if (this->option.get_type() == Constants::CALL)
	{
		price = spot * NormalCDF(d1, 0, 1) - strike * exp(-rf*mat) * NormalCDF(d2, 0, 1);
		this->delta = NormalCDF(d1, 0, 1);
	}
	else if (this->option.get_type() == Constants::PUT)
	{
		price = -spot * NormalCDF(-d1, 0, 1) + strike * exp(-rf*mat) * NormalCDF(-d2, 0, 1);
		this->delta = 1 - NormalCDF(d1, 0, 1);
	}
	else
	{
		price = spot * NormalCDF(d1, 0, 1) - strike * exp(-rf*mat) * NormalCDF(d2, 0, 1);
		this->delta = NormalCDF(d1, 0, 1);
	}

	this->vega = spot * sqrt(mat) * NormalCDF(d1, 0, 1);
	this->gamma = NormalCDF(d1, 0, 1) / (spot * this->delta * sqrt(mat));

	this->checkResultFile();
	this->exportPricing(Constants::BSM, price);

	return price;
}

double OptionPricer::get_mc_price(int a_nb_simul, int a_step)
{
	//
	// Return the Monte Carlo price of an option
	//

	int size_y 							= a_nb_simul;
	int size_x 							= (int)(a_step * this->tenor);
	vector< vector<double> > all_simul	= vector< vector<double> >();
	vector<double> one_simul				= vector<double>();
	vector<double> simul_prices			= vector<double>();
	double one_mean						= 0.00;
	double price 						= 0.00;
	double rf 							= 0.02;
	double one_price 					= 0.00;

	srand(time(NULL));

	for(int i = 0; i < size_y; i++)
	{
		one_simul.clear();
		one_simul.push_back(this->spot);
		one_mean = 0.00;

		for (int j = 1; j < size_x; j++)
		{
			//one_simul.push_back(one_simul[j-1] * (1 + (rf *1.00/a_step + this->udl.get_vol() * sqrt(1.00/a_step) *  NormalCDF(rand_a_b(0,1), 0, 1))));
			one_simul.push_back(one_simul[j-1] *(1 + rf *1.00/a_step + this->udl.get_vol() * sqrt(1.00/a_step) *  NormalCDFInverse(rand_a_b(0,1))));

			if (j == size_x - 1)
			{
				one_mean = one_simul[j];
			}
		}

		one_price = 0;
		if (this->option.get_type() == Constants::CALL)
		{
			one_price = one_mean - this->strike;
			one_price = std::max(one_price, 0.00);

			simul_prices.push_back(one_price);
			price += one_price;
		}
		else if (this->option.get_type() == Constants::PUT)
		{
			one_price = this->strike - one_mean;
			one_price = std::max(one_price, 0.00);

			simul_prices.push_back(one_price);
			price += one_price;
		}
		else
		{
			one_price = one_mean - this->strike;
			one_price = std::max(one_price, 0.00);

			simul_prices.push_back(one_price);
			price += one_price;
		}

		all_simul.push_back(one_simul);
	}

	price /= size_y;

	this->checkResultFile();
	this->exportPricing(Constants::MC, price);

	return max(price, 0.00);
}

double OptionPricer::get_binom_price(double step_p_year)
{
	///
	/// Return the Binomial price of an option
	///

	string one_type = this->option.get_type();
	int tenor = this->tenor;
	double vol  = this->udl.get_vol();
	double rf = this->option.get_rf();
	double strike = this->option.get_strike();
	double spot = this->option.get_udl().get_price();
	vector< vector<double> > mainTree;
	vector< vector<double> > mainTree2;
	vector<double> onePath;
	double u = exp(vol*pow(tenor, 1/2));
	double d = exp(-vol*pow(tenor, 1/2));
	double P = (exp(rf * 1/step_p_year) - d) / (u-d);
	double result;

	// Remplissage de l'arbre
	onePath.push_back(spot);
	mainTree.push_back(onePath);
	for (int i_main_step = 1; i_main_step < tenor*step_p_year; i_main_step ++)
	{
		onePath.clear();

		for (int i_one_step = 0; i_one_step < i_main_step; i_one_step++)
		{
			onePath.push_back(mainTree[i_main_step-1][i_one_step] * (d));

			if (i_one_step == i_main_step - 1)
			{
				onePath.push_back(mainTree[i_main_step-1][i_one_step] * (u));
			}
		}
		mainTree.push_back(onePath);

		// Lors de la dernière itération, remplissage de la dernière colonne de l'arbre secondaire avec la valeuur présente des options
		if (i_main_step == tenor*step_p_year-1)
		{
			onePath.clear();

			if (one_type == Constants::CALL)
			{
				for (int i_one_step = 0; i_one_step <= i_main_step; i_one_step++)
				{
					onePath.push_back(mainTree[i_main_step][i_one_step]-strike);
				}
			}
			else if (one_type == Constants::PUT)
			{
				for (int i_one_step = 0; i_one_step <= i_main_step; i_one_step++)
				{
					onePath.push_back(strike-mainTree[i_main_step][i_one_step]);
				}
			}
			mainTree2.push_back(onePath);
		}
	}

	// Calcul des valeurs présentes en partant de la dernière colonne de l'arbre secondaire
	for (int i_main_step =  0; i_main_step < tenor*step_p_year-1; i_main_step++)
	{
		onePath.clear();

		for (int i_one_step = 0; i_one_step < (tenor*step_p_year-i_main_step)-1; i_one_step++)
		{
			onePath.push_back((mainTree2[i_main_step][i_one_step]) * (1-P) + (mainTree2[i_main_step][i_one_step+1]) * (P));
			result = (mainTree2[i_main_step][i_one_step]) * (1-P) + (mainTree2[i_main_step][i_one_step+1]) * (P);
		}
		mainTree2.push_back(onePath);
	}

	return max(result, 0.00);
}

Stock OptionPricer::get_udl() const
{
	return this->udl;
}
void OptionPricer::set_udl(Stock a_one_stock)
{
	this->udl = a_one_stock;
}

Option OptionPricer::get_option() const
{
	return this->option;
}
void OptionPricer::set_option(Option a_one_option)
{
	this->option = a_one_option;
}

double OptionPricer::get_strike() const
{
	return this->strike;
}

void OptionPricer::set_strike(double a_one_strike)
{
	this->strike = a_one_strike;
}

double OptionPricer::get_spot() const
{
	return this->spot;
}

void OptionPricer::set_spot(double a_one_spot)
{
	this->spot = a_one_spot;
}

double OptionPricer::get_tenor() const
{
	return this->tenor;
}

void OptionPricer::set_tenor(double a_one_tenor)
{
	this->tenor = a_one_tenor;
}

double OptionPricer::get_vega() const
{
	return this->vega;
}

double OptionPricer::get_delta() const
{
	return this->delta;
}

double OptionPricer::get_gamma() const
{
	return this->gamma;
}

void OptionPricer::exportPricing(string method, double price)
{
	//
	// Export the result of every pricing in the file result.txt
	//

	ofstream w_result_file;
	ifstream r_result_file;
	string buff 					= "";

	//w_result_file.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/result.txt", ios::app);
	//r_result_file.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/result.txt");
	//w_result_file.open("src/txt/result.txt", ios::app);
	//r_result_file.open("src/txt/result.txt");

	w_result_file.open(Constants::PATH2RESULTS, ios::app);
	r_result_file.open(Constants::PATH2RESULTS);

	if (w_result_file.is_open() && r_result_file.is_open() )
	{
		r_result_file.seekg(-5, ios::end);
		getline(r_result_file, buff);

		if (buff == "PRICE")
		{
			w_result_file << endl;
		}

		w_result_file << method << "/" << this->option.get_type() << "/" << this->udl.get_name() << "/";
		w_result_file << this->spot << "/" << this->udl.get_vol() << "/" << this->strike << "/" << this->tenor << "/" << price << endl;
		w_result_file.close();
		r_result_file.close();
	}
	else
	{
		cout << "FILE NOT FOUND" << endl;
		exit(EXIT_FAILURE);
	}
}

bool OptionPricer::checkResultFile()
{
	//
	//	Check if result file header is the good one : "METHOD/PRODUCT_TYPE/STOCK_NAME/SPOT/VOLATILITY/STRIKE/MATURITY/PRICE"
	//	If not, the method replace it.
	//

	ifstream r_result_file;
	ofstream w_result_file;
	string one_line 				= "";
	string crt_header 			= "";
	string wtd_result 			= "METHOD/PRODUCT_TYPE/STOCK_NAME/SPOT/VOLATILITY/STRIKE/MATURITY/PRICE";
	bool good_header 			= true;
	string plain_text 			= "";
	string buff 					= "";

	//r_result_file.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/result.txt");
	//w_result_file.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/new_result.txt");
	//r_result_file.open("src/txt/result.txt");
	//w_result_file.open("src/txt/new_result.txt");
	r_result_file.open(Constants::PATH2RESULTS);
	w_result_file.open(Constants::PATH2NEW_RESULTS);

	if (r_result_file.is_open() && w_result_file.is_open())
	{
		getline(r_result_file, crt_header);

		if (crt_header != wtd_result)
		{
			w_result_file << wtd_result << endl;
			good_header = false;

			while(!r_result_file.eof())
			{
				getline(r_result_file, one_line);

				w_result_file << one_line << endl;
			}

			//remove("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/result.txt");
			//rename("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/new_result.txt",
					//"/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/result.txt");
			//remove("src/txt/result.txt");
			//rename("src/txt/new_result.txt", "src/txt/result.txt");
			remove((char*)&(Constants::PATH2RESULTS));
			rename((char*)&(Constants::PATH2NEW_RESULTS), (char*)&(Constants::PATH2RESULTS));

		}
		else
		{
			//remove("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/new_result.txt");
			//remove("src/new_result.txt");
			remove((char*)&(Constants::PATH2NEW_RESULTS));
		}

		r_result_file.close();
		w_result_file.close();
	}
	else
	{
		cout << "FILE NOT FOUND" << endl;
		exit(EXIT_FAILURE);
	}

	return good_header;
}

ostream& operator<<(ostream& flux, OptionPricer one_option_pricer)
{
	flux << "OptionPricer's Option :" << endl << one_option_pricer.get_option() << endl;
	flux << "BS price : " << endl;
	flux << "->" << one_option_pricer.get_bs_price() << endl;
	flux << "MC price : " << endl;
	flux << "->" << one_option_pricer.get_mc_price(500,365) << endl;
	flux << "Binomial price : " << endl;
	flux << "->" << one_option_pricer.get_binom_price(1000) << endl;
	flux << "Delta :" << endl;
	flux << one_option_pricer.get_delta() << endl;
	flux << "Vega :" << endl;
	flux << one_option_pricer.get_vega() << endl;
	flux << "Gamma :" << endl;
	flux << one_option_pricer.get_gamma() << endl;

	return flux;
}


