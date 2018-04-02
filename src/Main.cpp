//============================================================================
// Name        : 0.cpp
// Author      : Virgile Amatp
// Version     :
// Copyright   : Université Paris Dauphine
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include "testSQL.h"
#include "TestPricing.h"
#include "ApplicationPricer.h"

using namespace std;

int main(int argc, char *argv[])
{
	string path 				= argv[0];
	vector<string> args 		= vector<string>();

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++ )
		{
			args.push_back(argv[i]);
		}

		if (args[0] == "test")
		{
			TestPricing::run();
		}
		else if(args[0] == "run")
		{
			ApplicationPricer::run();
		}
		else
		{
			cout << "Wrong args." << endl << "Please choose args between 'test' or 'run'" << endl;
		}
	}
	else
	{
		TestPricing::run();
		ApplicationPricer::run();
	}

	return 0;
}
