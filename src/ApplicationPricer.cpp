/*
 * ApplicationPricer.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: virgileamato
 */

#include "ApplicationPricer.h"

void ApplicationPricer::run()
{
	string one_answer 				= "";
	char* index						= 0;
	string answer_pricing 			= "";
	bool pricing 					= true;
	int compt 						= 0;
	string type 						= "";
	string udl_name 					= "";
//	Stock udl 						= Stock::Stock();
//	Option option				 	= Option::Option();
//	OptionPricer option_pricer 		= OptionPricer::OptionPricer();
	double strike 					= 0.00;
	double udl_price 				= 0.00;
	double vol 						= 0.00;
	double mat 						= 0.00;
	double rf 						= 0.00;
	int method_input					= 0;
	string method					= "";
	bool good_answer 				= false;
	int size_input 					= 0;

	cout << " _____   _____   _____   _   _____   __   _        _____   _____    _   _____   _____   _____" << endl;
	cout << "/  _  \\ |  _  \\ |_   _| | | /  _  \\ |  \\ | |      |  _  \\ |  _  \\  | | /  ___| | ____| |  _  \\" << endl;
	cout << "| | | | | |_| |   | |   | | | | | | |   |  |      | |_| | | |_| |  | | | |     | |__   | |_| |" << endl;
	cout << "| | | | |  ___/   | |   | | | | | | | |\\   |      |  ___/ |  _  /  | | | |     |  __|  |  _  /" << endl;
	cout << "| |_| | | |       | |   | | | |_| | | | \\  |      | |     | | \\ \\  | | | |___  | |___  | | \\ \\" << endl;
	cout << "\\_____/ |_|       |_|   |_| \\_____/ |_|  \\_|      |_|     |_|  \\_\\ |_| \\_____| |_____| |_|  \\_\\" << endl << endl << endl << endl;

	while (pricing)
	{
		while(not good_answer)
		{
			if (compt==0)
			{
				cout << "Voulez vous pricer une option ?" << endl;
			}
			else
			{
				cout << "Souhaitez vous pricer une autre option ?" << endl;
			}
			cin >> answer_pricing;

			size_input = answer_pricing.length();

			for (int i = 0; i <= size_input; i++)
			{
				answer_pricing[i] = toupper(answer_pricing[i]);
			}

			if (answer_pricing == Constants::OUI || answer_pricing == Constants::NON || answer_pricing == Constants::NO || answer_pricing == Constants::YES)
			{
				good_answer = true;
			}
			else
			{
				cerr << "Veuillez préciser une réponse entre oui/yes et non/no" << endl;
				cerr.flush();
			}
		}
		good_answer = false;

		if (answer_pricing == Constants::OUI || answer_pricing == Constants::YES)
		{
			pricing = true;
		}
		else if (answer_pricing == Constants::NON || answer_pricing == Constants::NO)
		{
			pricing = false;
			break;
		}
		else
		{
			pricing = false;
			break;
		}

		while(not good_answer)
		{
			cout << "Quelle type d'option est-ce ?" << endl;
			cin >> type;
			std::transform(type.begin(), type.end(), type.begin(), ::toupper);

			if (type == Constants::CALL || type == Constants::PUT)
			{
				good_answer = true;
			}
			else
			{
				cerr << "Veuillez préciser si vous souhaitez pricer un call ou un put" << endl;
			}
		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle est le nom du sous jacent ?" << endl;
			cin >> udl_name;

			if (std::isalpha(udl_name[0]))
			{
				good_answer = true;
				udl_name[0] = toupper(udl_name[0]);
			}
			else
			{
				cerr << "Veuillez préciser un nom littéral (exemple: Apple)" << endl;
			}
		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle est le prix du sous jacent ?" << endl;
			cin >> one_answer;

			index = std::find(std::begin(Constants::NUMBERS), std::end(Constants::NUMBERS), one_answer[0]);

			if (index != std::end(Constants::NUMBERS))
			{
				udl_price = stod(one_answer);

				if (udl_price > 0 && udl_price <= 9999)
				{
					good_answer = true;
				}
				else
				{
					good_answer = false;
					//cout << "Veuillez préciser un nombre entre 0 et 9999" << endl;
					cerr << "Veuillez préciser un nombre entre 0 et 9999" << endl;
				}
			}
			else
			{
				cerr << "Veuillez préciser une valeur numérique comprise entre 0 et 9999" << endl;
			}
		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle est la volatilité du sous jacent ?" << endl;
			cin >> one_answer;

			index = std::find(std::begin(Constants::NUMBERS), std::end(Constants::NUMBERS), one_answer[0]);

			if (index != std::end(Constants::NUMBERS))
			{
				vol = stod(one_answer);
				if (vol >= 0 && vol <= 5)
				{
					good_answer = true;
				}
				else
				{
					cerr << "Veuillez préciser un nombre entre 0 et 5" << endl;
				}
			}
			else
			{
				cerr << "Veuillez préciser un nombre entre 0 et 5" << endl;
			}

		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle est le strike de l'option ?" << endl;
			cin >> one_answer;

			index = std::find(std::begin(Constants::NUMBERS), std::end(Constants::NUMBERS), one_answer[0]);

			if (index != std::end(Constants::NUMBERS))
			{
				strike = stod(one_answer);

				if (strike > 0 && strike <= 9999)
				{
					good_answer = true;
				}
				else
				{
					cerr << "Veuillez préciser un nombre entre 0 et 9999" << endl;
				}
			}
			else
			{
				cerr << "Veuillez préciser un nombre entre 0 et 9999" << endl;
			}

		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle est la maturité de l'option ?" << endl;
			cin >> one_answer;

			index = std::find(std::begin(Constants::NUMBERS), std::end(Constants::NUMBERS), one_answer[0]);

			if (index != std::end(Constants::NUMBERS))
			{
				mat = stod(one_answer);

				if (mat > 0 && mat <= 100)
				{
					good_answer = true;
				}
				else
				{
					cerr << "Veuillez préciser un nombre entre 0 et 100" << endl;
				}
			}
			else
			{
				cerr << "Veuillez préciser un nombre entre 0 et 100" << endl;
			}

		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle est le taux sans risque de l'option ?" << endl;
			cin >> one_answer;

			index = std::find(std::begin(Constants::NUMBERS), std::end(Constants::NUMBERS), one_answer[0]);

			if (index != std::end(Constants::NUMBERS))
			{

				rf = stod(one_answer);

				if (rf >= -0.2 && rf <= 1)
				{
					good_answer = true;
				}
				else
				{
					cerr << "Veuillez préciser un nombre entre -0.2 et 1" << endl;
				}
			}
			else
			{
				cerr << "Veuillez préciser un nombre entre -0.2 et 1" << endl;
			}
		}
		good_answer = false;

		while(not good_answer)
		{
			cout << "Quelle méthode de Pricing souhaitez vous utiliser ?" << endl;
			cout << "	- [1] 	=> 		Black and Scholes" << endl;
			cout << "	- [2] 	=> 		Monte-Carlo" << endl;
			cout << "	- [3] 	=> 		Binomial Tree" << endl;
			cin >> one_answer;

			index = std::find(std::begin(Constants::NUMBERS), std::end(Constants::NUMBERS), one_answer[0]);

			if (index != std::end(Constants::NUMBERS))
			{
				method_input = stod(one_answer);

				if (method_input == 1 || method_input == 2 || method_input == 3)
				{
					good_answer = true;

					if (method_input == Constants::Methods::BlackScholes)
					{
						method = Constants::BSM;
					}
					else if (method_input == Constants::Methods::MonteCarlo)
					{
						method = Constants::MC;
					}
					else if (method_input == Constants::Methods::Binomial)
					{
						method = Constants::BINOMIAL;
					}
					else
					{
						cerr << "La méthode n'a pas été reconnue !" << endl <<  "Valeur par défaut : Black & Scholes" << endl;
						method = Constants::BSM;
					}
				}
				else
				{
					cerr << "Veuillez préciser une valeur : 1, 2 ou 3" << endl;
				}
			}
		}
		good_answer = false;

//		udl = Stock::Stock(udl_name, udl_price, vol);
//		option = Option::Option(udl,strike, mat, rf, type);
//		option_pricer = OptionPricer::OptionPricer(option);

		Stock udl(udl_name, udl_price, vol);
		Option option(udl,strike, mat, rf, type);
		OptionPricer option_pricer(option);

		cout << "Nous pricons donc :" << endl;
		cout << "	- Un " << type << endl;
		cout << "	- Sur " << udl.get_name() << endl;
		cout << "	- De strike " << strike <<  endl;
		cout << "	- De spot " << udl.get_price() << endl;
		cout << "	- De volatilité " << udl.get_vol() << endl;
		cout << "	- De maturité " << mat << endl;
		cout << "	- Sachant un taux sans risque de " << rf << endl;
		cout << " 	- Nous pricons avec la méthode " << method << endl;
		cout << endl << "==> Le prix de l'option est de : " << option_pricer.get_price(method) << endl << endl;
		option_pricer.get_bs_price();
		cout << endl << "==> Son Delta est de : " << option_pricer.get_delta() << endl << endl;
		cout << endl << "==> Son Gamma est de : " << option_pricer.get_gamma() << endl << endl;
		cout << endl << "==> Son Vega est de : " << option_pricer.get_vega() << endl << endl;
		compt ++;
	}

	cout << "Comme vous voudrez" << endl << "Fermeture de l'application ..." << endl;

	cout << "    ____                  " << endl;
	cout << "  ____ _____  ____  ____/ / /_  __  _____" << endl;
	cout << " / __ `/ __ \\/ __ \\/ __  / __ \\/ / / /_\\" << endl;
	cout << "/ /_/ / /_/ / /_/ / /_/ / /_/ / /_/ /  __/ _ _" << endl;
	cout << "\__, /\____/\____/\__,_/_.___/\__, /\___(_|_|_)" << endl;
	cout << "/____/                        /____/" << endl;
}

