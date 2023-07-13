//Yilin Yang
//Programming Finance HW9

#include <iostream>
#include "package_yilin_yang.h"

using std::string;

Package::Package
(
	string s1, string s2, string s3, string s4, string s5,
	string r1, string r2, string r3, string r4, string r5,
	double w, double c, string t
)
{
	name_S = s1;
	address_S = s2;
	city_S = s3;
	state_S = s4;
	zip_S = s5;

	name_R = r1;
	address_R = r2;
	city_R = r3;
	state_R = r4;
	zip_R = r5;
	
	weight = w > 0.0 ? w : 0.0;
	cost = c > 0.0 ? c : 0.0;

	type = t;
}

//return sender info
string Package::get_name_S()
{
	return name_S;
}

string Package::get_address_S()
{
	return address_S;
}

string Package::get_city_S()
{
	return city_S;
}

string Package::get_state_S()
{
	return state_S;
}

string Package::get_zip_S()
{
	return zip_S;
}

//return recipient info
string Package::get_name_R()
{
	return name_R;
}

string Package::get_address_R()
{
	return address_R;
}

string Package::get_city_R()
{
	return city_R;
}

string Package::get_state_R()
{
	return state_R;
}

string Package::get_zip_R()
{
	return zip_R;
}

//return weight/cost
double Package::get_weight()
{
	return weight;
}

double Package::get_cost()
{
	return cost;
}

double Package::calculate_cost()
{
	return get_weight()*get_cost();
}

string Package::get_type()
{
	return type;
}