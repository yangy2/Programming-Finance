//Yilin Yang
//Programming Finance HW9

#pragma once
#ifndef OVERNIGHT_YILIN_YANG_H
#define OVERNIGHT_YILIN_YANG_H

#include "package_yilin_yang.h"

using std::string;

class overnightpackage : public Package
{
public:

	//constructor
	overnightpackage
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
