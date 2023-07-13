//Yilin Yang
//Programming Finance HW9

#include <iostream>
#include "twodaypack_yilin_yang.h"

using std::string;

twodaypackage::twodaypackage
(
	string s1, string s2, string s3, string s4, string s5,
	string r1, string r2, string r3, string r4, string r5,
	double w, double c, string t, double f
) : Package(s1, s2, s3, s4, s5, r1, r2, r3, r4, r5, w, c, t)
{
	fee = f > 0.0 ? f : 0.0;
}

double twodaypackage::get_fee()
{
	return fee;
}

double twodaypackage::calculate_cost()
{
	return get_weight()*(get_cost() + get_fee());
}