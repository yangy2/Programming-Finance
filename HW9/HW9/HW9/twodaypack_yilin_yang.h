//Yilin Yang
//Programming Finance HW9

#pragma once
#ifndef TWODAYPACK_YILIN_YANG_H
#define TWODAYPACK_YILIN_YANG_H

#include "package_yilin_yang.h"

using std::string;

class twodaypackage : public Package
{
public:

	//constructor
	twodaypackage
	(
		string, string, string, string, string,
		string, string, string, string, string,
		double, double, string, double
	);

	virtual double calculate_cost();
	double get_fee();

private:
	double fee;
};
#endif
