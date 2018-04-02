/*
 * Tools.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: virgileamato
 */

#include "Tools.h"

using namespace std;

// Returns the erf() of a value (not super precice, but ok)
double erf(double x)
{
 double y = 1.0 / ( 1.0 + 0.3275911 * x);
 return 1 - (((((
        + 1.061405429  * y
        - 1.453152027) * y
        + 1.421413741) * y
        - 0.284496736) * y
        + 0.254829592) * y)
        * exp (-x * x);
}

// Returns the probability of x, given the distribution described by mu and sigma.
double NormalPDF(double x, double mu, double sigma)
{
  //Constants
  static const double pi = 3.14159265;
  return exp( -1 * (x - mu) * (x - mu) / (2 * sigma * sigma)) / (sigma * sqrt(2 * pi));
}

// Returns the probability of [-inf,x] of a gaussian distribution
double NormalCDF(double x, double mu, double sigma)
{
	return 0.5 * (1 + erf((x - mu) / (sigma * sqrt(2.))));
}

double RationalApproximation(double t)
{
    // Abramowitz and Stegun formula 26.2.23.
    // The absolute value of the error should be less than 4.5 e-4.
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) /
               (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}

double NormalCDFInverse(double p)
{
    if (p <= 0.0 || p >= 1.0)
    {
        std::stringstream os;
        os << "Invalid input argument (" << p
           << "); must be larger than 0 but less than 1.";
        throw std::invalid_argument( os.str() );
    }

    // See article above for explanation of this section.
    if (p < 0.5)
    {
        // F^-1(p) = - G^-1(p)
        return -RationalApproximation( sqrt(-2.0*log(p)) );
    }
    else
    {
        // F^-1(p) = G^-1(1-p)
        return RationalApproximation( sqrt(-2.0*log(1-p)) );
    }
}

double rand_a_b(double a, double b)
{
	//srand(time(NULL));

	double result = rand()/(double)RAND_MAX*(b-a)+a;

	return result;
}

std::string getOsName()
{
    #ifdef _WIN32
    return "WINDOWS";
    #elif _WIN64
    return "WINDOWS";
    #elif __unix || __unix__
    return "UNIX";
    #elif __APPLE__ || __MACH__
    return "MACOS";
    #elif __linux__
    return "LINUX";
    #elif __FreeBSD__
    return "FREEBSD";
    #else
    return "Other";
    #endif
}
