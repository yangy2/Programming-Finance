//Yilin Yang
//Programming Finance HW7

#include <iostream>
#include "polynomial_yilin_yang.h"

using std::cout;
using std::cin;
using std::endl;

//wipes the standard input stream clean
void polynomial::refresh_cin()
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

//read user input for polynomial terms, coefficients, and exponents
void polynomial::getdata()
{
	do
	{
		cout << "\tEnter number of polynomial terms: ";
		cin >> terms;
		if (cin.fail() || terms < 1 || terms > 6) //Error checking if input is not valid
		{
			cout << "\t\tNumber of terms must be positive integer up to 6" << endl;
		}
		refresh_cin();
	} while (terms < 1 || terms > 6); //Repeat if input was invalid

	for (int i = 0; i < terms; i++)
	{
		int coeff = 0;
		int exp = 0;

		cout << "Reading term #" << i + 1 << endl;
		do
		{
			cout << "\tEnter coefficient and exponent: ";
			cin >> coeff >> exp;
			if (cin.fail() || exp < 1 || exp > 6) //Error checking if input is not valid
			{
				cout << "\t\tCoefficient and Exponent must be integers" << endl;
				cout << "\t\tExponent must be between 1 and 6 (inclusive)" << endl;
			}
			refresh_cin();
		} while (cin.fail() || exp < 1 || exp > 6); //Repeat if input was invalid

//		cout << "You input " << coeff << " and " << exp << endl;
		setdata(coeff, exp);
	}
}

//set polynomial term based on coefficient and exponent input
void polynomial::setdata(int coeff, int exp)
{
	P[exp] += coeff;
}

//allow for std::cout to print polynomial
ostream &operator<<(ostream &output, const polynomial poly)
{
	int count = 0, check = 0;

	//count terms in polynomial
	for (int i = 0; i < size; i++)
	{
		if (poly.P[i] != 0) count++;
	}

	//print polynomial terms
	if (count != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (poly.P[i] != 0)
			{
				check++;
				output << poly.P[i] << "x"; //print coefficient
				if (i != 1) output << "^" << i; //print exponent if there is one
				if (check != count) output << " + "; //print addition sign if not the last term
			}
		}
	}
	else output << "0";

	return output;
}

//allow for + operator to add two polynomials
polynomial polynomial::operator+(polynomial poly)
{
	polynomial result;
	for (int i = 0; i < size; i++)
	{
		result.P[i] = P[i] + poly.P[i];
	}
	return result;
}

//allow for += operator to add two polynomials
polynomial polynomial::operator+=(polynomial poly)
{
	polynomial result;
	for (int i = 0; i < size; i++)
	{
		result.P[i] = P[i] + poly.P[i];
	}
	cout << result << endl;
	return result;
}

//allow for - operator to subtract two polynomials
polynomial polynomial::operator-(polynomial poly)
{
	polynomial result;
	for (int i = 0; i < size; i++)
	{
		result.P[i] = P[i] - poly.P[i];
	}
	return result;
}

//allow for -= operator to subtract two polynomials
polynomial polynomial::operator-=(polynomial poly)
{
	polynomial result;
	for (int i = 0; i < size; i++)
	{
		result.P[i] = P[i] - poly.P[i];
	}
	cout << result << endl;
	return result;
}

//allow for * operator to multiply two polynomials
polynomial polynomial::operator*(polynomial poly)
{
	polynomial result;
	int res[size*2][size*2] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i][i + j] = P[i] * poly.P[j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result.P[i] = result.P[i] + res[j][i];
		}
	}

	return result;

}

//allow for *= operator to multiply two polynomials
polynomial polynomial::operator*=(polynomial poly)
{
	polynomial result;
	int res[size * 2][size * 2] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			res[i][i + j] = P[i] * poly.P[j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result.P[i] = result.P[i] + res[j][i];
		}
	}

	cout << result << endl;
	return result;

}

//allow for = operator to assign one polynomial to another
void polynomial::operator=(polynomial poly)
{
	for (int i = 0; i < size; i++)
	{
		P[i] = poly.P[i];
	}
}