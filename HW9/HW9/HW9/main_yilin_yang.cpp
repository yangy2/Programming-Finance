//Yilin Yang
//Programming Finance HW9

#include <iostream>
#include <vector>
#include <iomanip>

#include "package_yilin_yang.h"
#include "twodaypack_yilin_yang.h"
#include "overnight_yilin_yang.h"

using std::cout;
using std::cin;
using std::endl;

void main()
{
	//vector of package pointers
	std::vector<Package*>list(3);

	//cost variables
	double costoz = 0.5;
	double twoday = 2;
	double oneday = 5;
	double total = 0;

	//initialize packages
	list[0] = new Package
	(
		"Yilin Yang", "55 Bevier Rd", "Piscataway", "NJ", "08854",
		"Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854",
		10, costoz, "Regular"
	);

	list[1] = new twodaypackage
	(
		"Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854",
		"Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854",
		5, costoz, "Two Day", twoday
	);

	list[2] = new overnightpackage
	(
		"John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854",
		"Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854",
		2, costoz, "Overnight", oneday
	);

	//print general info
	cout << std::fixed << std::setprecision(2);
	cout << "######### PACKAGE DELIVERY SERVICE PROGRAM #########" << endl;
	cout << "Cost for a package: $" << costoz << "/ounce" << endl;
	cout << "Additional cost for two day delivery: $" << twoday << "/ounce" << endl;
	cout << "Additional cost for overnight delivery: $" << oneday << "/ounce" << endl;
	cout << endl;

	//print packages in vector
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Package " << i + 1 << endl;
		cout << "\tSender:" << endl;
		cout << "\t" << list[i]->get_name_S() << endl;
		cout << "\t" << list[i]->get_address_S() << endl;
		cout << "\t" << list[i]->get_city_S() << ", ";
		cout << list[i]->get_state_S() << " ";
		cout << list[i]->get_zip_S() << endl;
		cout << endl;
		cout << "\tRecipient:" << endl;
		cout << "\t" << list[i]->get_name_R() << endl;
		cout << "\t" << list[i]->get_address_R() << endl;
		cout << "\t" << list[i]->get_city_R() << ", ";
		cout << list[i]->get_state_R() << " ";
		cout << list[i]->get_zip_R() << endl;
		cout << endl;
		cout << "\tWeight of package: " << list[i]->get_weight() << " ounces" << endl;
		cout << "\tType of delivery: " << list[i]->get_type() << " Delivery" << endl;
		cout << "\tCost of Package: $" << list[i]->calculate_cost() << endl;
		cout << endl;
		total += list[i]->calculate_cost();
	}
	cout << "Total cost of all packages: $" << total << endl;
	cout << "Press ENTER to quit" << endl;
	cin.get();
}