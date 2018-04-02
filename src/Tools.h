/*
 * Tools.h
 *
 *  Created on: Jan 12, 2018
 *      Author: virgileamato
 */

#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
//#include <ctime>
#include <time.h>

double erf(double x);

double NormalPDF(double x, double mu, double sigma);

double NormalCDF(double x, double mu, double sigma);

double NormalCDFInverse(double p);

double RationalApproximation(double t);

double rand_a_b(double a, double b);

std::string getOsName();

