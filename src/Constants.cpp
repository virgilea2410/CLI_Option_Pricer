/*
 * Constants.cpp
 *
 *  Created on: Jan 26, 2018
 *      Author: virgileamato
 */

#include "Constants.h"

const string Constants::BSM = "BlackScholes";
const string Constants::MC = "MonteCarlo";
const string Constants::BINOMIAL = "Binomial";

const string Constants::CALL = "CALL";
const string Constants::PUT = "PUT";

const string Constants::YES = "YES";
const string Constants::OUI = "OUI";
const string Constants::NO = "NO";
const string Constants::NON = "NON";

char Constants::NUMBERS[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

string const Constants::OS =  getOsName();

string Constants::GetCWD()
{
	 #ifdef SUBDIRS
		#define QUDI(x) #x
		#define QUdi(x) QUDI(x)
		#define SUBDIRS_IS_DEF TRUE
	#endif 
	#ifndef SUBDIRS
		#define SUBDIRS FALSE
		#define SUBDIRS_IS_DEF FALSE
		#define QUDI(x) #x
		#define QUdi(x) QUDI(x)
	#endif

	string one_cwd;
	int index;
	string word_to_find = "Option_Pricer";
	int word_length = word_to_find.size();

	if (OS == "MACOS")
	{
		one_cwd = QUdi(SUBDIRS);

		if (one_cwd == "FALSE")
		{
			one_cwd = getenv("PWD");
			index = one_cwd.find(word_to_find);
			one_cwd = one_cwd.substr(0, 45 + word_length + 1);
			one_cwd = one_cwd + "src";
		}
	}
	else if (OS == "WINDOW")
	{
		one_cwd = QUdi(SUBDIRS);

		if (one_cwd == "FALSE")
		{
			one_cwd = getenv("%CD%");
		}
	}
	else
	{
		one_cwd = QUdi(SUBDIRS);

		if (one_cwd == "FALSE")
		{
			one_cwd = getenv("PWD");
			index = one_cwd.find(word_to_find);
			one_cwd = one_cwd.substr(0, 45 + word_length + 1);
			one_cwd = one_cwd + "src";
		}
	}

	return one_cwd;
}

string const Constants::CWD = Constants::GetCWD();
//string const Constants::PATH2TXT = "../Option_Pricer/src/txt/";
//string const Constants::PATH2TXT = "src/txt/";
string const Constants::PATH2TXT = CWD + "/txt/";
string const Constants::PATH2METHODS = PATH2TXT + "methods.txt";
string const Constants::PATH2RESULTS = PATH2TXT + "result.txt";
string const Constants::PATH2NEW_RESULTS = PATH2TXT + "new_result.txt";
string const Constants::PATH2PRICING = PATH2TXT + "pricing.txt";
