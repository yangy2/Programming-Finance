//Yilin Yang
//Programming Finance HW9

#pragma once
#ifndef PACKAGE_YILIN_YANG_H
#define PACKAGE_YILIN_YANG_H

#include <iostream>
#include <string>

using std::string;

class Package
{
public:

	//constructor
	Package
	(
		string, string, string, string, string,
		string, string, string, string, string,
		double, double, string
	);

	//return sender info
	string get_name_S();
	string get_address_S();
	string get_city_S();
	string get_state_S();
	string get_zip_S();

	//return recipient info
	string get_name_R();
	string get_address_R();
	string get_city_R();
	string get_state_R();
	string get_zip_R();

	//return weight/cost
	double get_weight();
	double get_cost();
	virtual double calculate_cost();

	string get_type();

private:
	string name_S;
	string address_S;
	string city_S;
	string state_S;
	string zip_S;

	string name_R;
	string address_R;
	string city_R;
	string state_R;
	string zip_R;

	double weight;
	double cost;

	string type;
};

#endif
