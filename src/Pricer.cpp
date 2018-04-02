/*
 * Pricer.cpp
 *
 *  Created on: Jan 11, 2018
 *      Author: virgileamato
 */


#include "Pricer.h"


Pricer::Pricer()
{
	std::string no_methods = "No Methods";

	this->methods.push_back(no_methods);
}

Pricer::Pricer(Pricer const& a_one_pricer)
{
	this->methods = a_one_pricer.get_methods();
}

Pricer::Pricer(vector<string> a_methods)
{
	int size_tab = a_methods.size();

	for (int i = 0; i < size_tab; i++)
	{
		this->methods.push_back(a_methods[i]);
	}
}

Pricer::Pricer(list<string> a_methods)
{
	int size_tab = a_methods.size();
	list<string>::iterator method_iterator = a_methods.begin();

	for (int i = 0; i < size_tab; i++)
	{
		this->l_methods.push_back(*method_iterator);
		method_iterator = next(method_iterator, 1);
	}
}

Pricer::~Pricer()
{
}

vector<string> Pricer::get_methods() const
{
	return this->methods;
}

list<string> Pricer::l_get_methods() const
{
	return this->l_methods;
}

string Pricer::get_one_method(int i) const
{
	return this->methods[i];
}

string Pricer::l_get_one_method(int i) const
{
	list<string>::const_iterator method_iterator = this->l_methods.begin();

	string result;

	advance(method_iterator, i);

	result = *method_iterator;

	return result;
}

void Pricer::set_one_method(string a_one_method)
{
	this->methods.push_back(a_one_method);
}

void Pricer::l_set_one_method(string a_one_method)
{
	this->l_methods.push_back(a_one_method);
}

void Pricer::set_methods(vector<string>& a_methods)
{
	int tab_size = a_methods.size();

	for (int i = 0; i < tab_size; i++)
	{
		this->methods.push_back(a_methods[i]);
	}
}

void Pricer::set_methods(vector<string> const& a_methods)
{
	int tab_size = a_methods.size();

	for (int i = 0; i < tab_size; i++)
	{
		this->methods.push_back(a_methods[i]);
	}
}

void Pricer::l_set_methods(list<string>& a_methods)
{
	int tab_size = a_methods.size();
	list<string>::iterator methods_iterator = a_methods.begin();

	for (int i = 0; i < tab_size; i++)
	{
		this->l_methods.push_back(*methods_iterator);
		methods_iterator = next(methods_iterator, 1);
	}
}

void Pricer::set_methods(string path_file_methods)
{
	ifstream file_methods;

	file_methods.open(path_file_methods);
	string ligne;

	if (file_methods)
	{
		while(getline(file_methods, ligne))
		{
			this->methods.push_back(ligne);
		}
	}
	else
	{
		cout << "FILE ERROR : Please Retry" << endl;
	}
}

void Pricer::set_methods(ifstream& file_methods)
{

	bool open = false;

	if (!file_methods.is_open())
	{
		//file_methods.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer_V1.0/src/methods.txt");
		//file_methods.open("src/txt/methods.txt");
		file_methods.open(Constants::PATH2METHODS);
		open = true;
	}

	string ligne;

	if (file_methods)
	{
		while(getline(file_methods, ligne))
		{
			this->methods.push_back(ligne);
		}
	}
	else
	{
		cout << "FILE ERROR : Please Retry" << endl;
	}
	 if (open)
	 {
		 file_methods.close();
	 }
}

void Pricer::f_add_one_method(string a_method)
{
	ifstream r_file_method;
	ofstream file_method;

	string ligne;

	bool already_here = false;

	//file_method.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer_V1.0/src/methods.txt", ios::app);
	//r_file_method.open("/Users/virgileamato/Projects-C++/Eclipse-IDE/Option_Pricer_V1.0/src/methods.txt");
	//file_method.open("src/txt/methods.txt", ios::app);
	//r_file_method.open("src/txt/methods.txt");
	file_method.open(Constants::PATH2METHODS, ios::app);
	r_file_method.open(Constants::PATH2METHODS);

	if (r_file_method.is_open())
	{
		while(getline(r_file_method, ligne))
		{
			if (a_method == ligne)
			{
				already_here = true;
				cout << "already here" << endl;
			}
		}
	}

	if (file_method.is_open())
	{
		if (!already_here)
		{
			file_method << a_method << endl;
			cout << "not already here" << endl;
		}

		file_method.close();
	}
}

void Pricer::print_methods()
{
	int size_tab = this->methods.size();

	cout << "Pricer methods : " << endl;

	for (int i = 0; i < size_tab; i ++)
	{
		cout << this->methods[i] << endl;
	}
}

void Pricer::l_print_methods()
{
	int l_tab_size = l_methods.size();

	for (int i=0; i < l_tab_size; i ++)
	{
		cout << this->l_get_one_method(i) << endl;
	}
}

void Pricer::clear_methods()
{
	int size_tab = this->methods.size();

	for (int i = 0; i < size_tab; i ++)
	{
		this->methods.pop_back();
	}
}

void Pricer::l_clear_methods()
{
	int size_tab = this->l_methods.size();

	for (int i = 0; i < size_tab; i ++)
	{
		this->l_methods.pop_back();
	}
}



