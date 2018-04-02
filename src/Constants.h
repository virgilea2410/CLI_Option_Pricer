/*
 * Constants.h
 *
 *  Created on: Jan 26, 2018
 *      Author: virgileamato
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <iostream>
#include <string>
#include "Tools.h"

using namespace std;

class Constants
{
public:
	static const string BSM;
	static const string MC;
	static const string BINOMIAL;

	static const string CALL;
	static const string PUT;

	static const string YES;
	static const string NO;
	static const string OUI;
	static const string NON;

	static char NUMBERS[10];

	static const string OS;
	static const string CWD;
	static string GetCWD();

	static const string PATH;
	static const string PATH2TXT;
	static const string PATH2METHODS;
	static const string PATH2RESULTS;
	static const string PATH2NEW_RESULTS;
	static const string PATH2PRICING;

	enum Methods
	{
		BlackScholes = 1,
		MonteCarlo,
		Binomial
	};
};


#endif /* CONSTANTS_H_ */
