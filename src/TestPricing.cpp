/*
 * TestPricing.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: virgileamato
 */

#include "TestPricing.h"
//#include <boost/filesystem.hpp>

void TestPricing::run()
{
	//
	// Function that test the Option_Pricer module
	//

//		Stock one_stock						= Stock::Stock();
//		Option one_option					= Option::Option();
//		Pricer one_pricer					= Pricer::Pricer();
//		Pricer l_one_pricer					= Pricer::Pricer();
//		OptionPricer one_option_pricer		= OptionPricer::OptionPricer();
//		Stock option_udl						= Stock::Stock();

		vector<string> pricer_methods		= vector<string>();
		string path							= "";

		// Stock, Option, Pricer and OptionPrcier initialisation
		Stock one_stock("APPLE", 100.00, 0.05);
		Option one_option(one_stock, 97.00, 1);
		OptionPricer one_option_pricer(one_option);

		// Methods initialisation
		pricer_methods.push_back("Methode 1");
		pricer_methods.push_back("Methode 2");
		pricer_methods.push_back("Methode 3");
		pricer_methods.push_back("Methode 4");

		Pricer one_pricer(pricer_methods);

		cout << one_stock;
		cout << endl;
		cout << one_option;

		one_pricer.print_methods();

		cout << "Now we clear all methods from vector" << endl;

		one_pricer.clear_methods();
		one_pricer.print_methods();

		cout << "Now, me set methods methods.txt in vector" << endl;

		//one_pricer.set_methods("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
		//one_pricer.set_methods("src/txt/methods.txt");
		one_pricer.set_methods(Constants::PATH2METHODS);
		one_pricer.print_methods();

		cout << "Another time, we clear all methods from vector" << endl;

		one_pricer.clear_methods();

		cout << "And now we set methods by directly passing a file in argument" << endl;

		//ifstream one_file("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/methods.txt");
		ifstream one_file(Constants::PATH2METHODS);

		one_pricer.set_methods(one_file);
		one_file.close();
		one_pricer.print_methods();

		cout << "Finnaly, we're going to add Augmented B&S as a method in the file method" << endl;

		one_pricer.f_add_one_method("Augmented B&S");
		one_pricer.print_methods();

		cout << "Maintenant, affichons les résultats des principales méthodes de pricing" << endl;
		cout << one_option_pricer << endl;

		cout << "Maintenant, on initialise un pricer à partir d'un fichier texte au format aggrégé: pricing.txt" << endl;

		cout << "En passant en argumant le chemin vers le fichier ... " << endl;
		//OptionPricer::OptionPricer other_option_pricer = OptionPricer::OptionPricer("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer/src/pricing.txt");
		//OptionPricer other_option_pricer = OptionPricer::OptionPricer("src/txt/pricing.txt");
		//OptionPricer other_option_pricer("src/txt/pricing.txt");
		OptionPricer other_option_pricer(Constants::PATH2PRICING);

		cout << other_option_pricer << endl;

		cout << "... Ou directement en lui passant en argumant le fichier ouvert" << endl;

		//ifstream one_pricing_file("src/txt/pricing.txt");
		ifstream one_pricing_file(Constants::PATH2PRICING);

		OptionPricer third_option_pricer(one_pricing_file);

		cout << third_option_pricer << endl << endl << endl;
}



