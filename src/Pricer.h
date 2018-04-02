/*
 * Pricer.h
 *
 *  Created on: Jan 11, 2018
 *      Author: virgileamato
 */


#ifndef PRICER_H_
#define PRICER_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include "Constants.h"


using namespace std;


class Pricer
{
	protected:
		vector<string> methods;
		list<string> l_methods;

	public:
		Pricer();
		Pricer(Pricer const& one_pricer);
		Pricer(vector<string> my_methods);
		Pricer(list<string> my_methods);
		~Pricer();

		vector<string> get_methods() const;
		list<string> l_get_methods() const;
		string get_one_method(int i) const;
		string l_get_one_method(int i) const;

		void set_one_method(string one_method);
		void l_set_one_method(string one_method);
		void set_methods(vector<string>& a_methods);
		void set_methods(vector<string> const& a_methods);
		void l_set_methods(list<string>& a_methods);
		void f_add_one_method(string method);
		void set_methods(ifstream& file_methods);
		void set_methods(string path_file_methods);

		void print_methods();
		void l_print_methods();

		void clear_methods();
		void l_clear_methods();
};


#endif /* PRICER_H_ */
