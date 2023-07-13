//Yilin Yang
//Programming Finance HW3
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void refresh_cin() //wipes the standard input stream clean
{
	cin.clear();
	cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
}

int print_menu() //print menu and read user's selection
{
	int choice;

	cout << "MENU" << endl;
	cout << "############################" << endl;
	cout << "# Choice 1: Addition       #" << endl;
	cout << "# Choice 2: Subtraction    #" << endl;
	cout << "# Choice 3: Multiplication #" << endl;
	cout << "# Choice 4: Transpose      #" << endl;
	cout << "# Choice 5: Determinant    #" << endl;
	cout << "# Choice 6: Inverse        #" << endl;
	cout << "# Choice 7: QUIT           #" << endl;
	cout << "############################" << endl;

	do
	{
		cout << "Enter Choice: ";
		cin >> choice;
		if (cin.fail() || choice < 1 || choice > 7) //Error checking if input is not valid
		{
			cout << "\tPlease enter a valid choice: 1, 2, 3, 4, 5, 6, or 7" << endl;
		}
		refresh_cin();
	} while (choice < 1 || choice > 7); //Repeat if input was invalid

	return choice;
}

void get_dimensions(int &rows, int &cols) //read user input for matrix dimensions
{
	do
	{
		cout << "\t\tEnter Number of Rows: ";
		cin >> rows;
		if (cin.fail() || rows < 1 || rows > 10) //Error checking if input is not valid
		{
			cout << "\t\t\tInput must be integer between 1 and 10" << endl;
		}
		refresh_cin();
	} while (rows < 1 || rows > 10); //Repeat if input was invalid

	do
	{
		cout << "\t\tEnter Number of Columns: ";
		cin >> cols;
		if (cin.fail() || cols < 1 || cols > 10) //Error checking if input is not valid
		{
			cout << "\t\t\tInput must be integer between 1 and 10" << endl;
		}
		refresh_cin();
	} while (cols < 1 || cols > 10); //Repeat if input was invalid

	cout << "\t\tMatrix Dimensions: " << rows << "x" << cols << endl;
}

void fill_matrix(int A[10][10], int rows, int cols) //read user input for matrix elements
{
	cout << "\t\tEnter value: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int x; //flag for a faulty input
			do
			{
				x = 0; //flag is zero, no issue

				cout << "\t\t[" << i + 1 << "][" << j + 1 << "]: ";
				cin >> A[i][j];
				if (cin.fail()) //Error checking if input is not vallid
				{
					cout << "\t\t\tInput must be an integer" << endl;
					x = 1; //flag is nonzero, issue
				}
				refresh_cin();
			} while (x != 0); //Repeat if input is invalid
		}
	}
}

void print_matrix(int A[10][10], int rows, int cols) //print contents of matrix
{
	for (int i = 0; i < rows; i++)
	{
		cout << "\t\t";
		for (int j = 0; j < cols; j++)
		{
			cout << A[i][j] << "\t"; 
		}
		cout << endl;
	}
}

void add(int A[10][10], int B[10][10], int C[10][10], int rows, int cols) //matrix addition
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	print_matrix(C, rows, cols);

}

void sub(int A[10][10], int B[10][10], int C[10][10], int rows, int cols) //matrix subtraction
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	print_matrix(C, rows, cols);

}

void mult(int A[10][10], int B[10][10], int C[10][10], int a_rows, int a_cols, int b_rows, int b_cols) //matrix multiplication
{
	for (int i = 0; i < a_rows; i++)
	{
		for (int j = 0; j < b_cols; j++)
		{
			for (int k = 0; k < b_rows; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	print_matrix(C, a_rows, b_cols);

}

void trans(int A[10][10], int C[10][10], int rows, int cols) //matrix transpose
{
	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			C[j][i] = A[i][j];
		}
	}
	print_matrix(C, cols, rows);

}

int det(int A[10][10]) //matrix determinant
{
	int det = A[0][0]*A[1][1]*A[2][2] + A[0][1]*A[1][2]*A[2][0] + A[0][2]*A[1][0]*A[2][1]
			- A[0][0]*A[1][2]*A[2][1] - A[0][1]*A[1][0]*A[2][2] - A[0][2]*A[1][1]*A[2][0];

	return det;
}

void inv(int A[10][10], int rows, int cols) //matrix inversion
{
	double x = det(A); //find determinant

	if (x != 0)
	{
		double C[3][3];
		double temp[3][3];
		//calculate inversion
		C[0][0] = (1 / x) * ( ( (A[1][1]) * (A[2][2]) ) - ( A[2][1] * A[1][2] ) );
		C[0][1] = (1 / x) * (-(A[1][0] * A[2][2] - A[1][2] * A[2][0]));
		C[0][2] = (1 / x) * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);
		C[1][0] = (1 / x) * (-(A[0][1] * A[2][2] - A[0][2] * A[2][1]));
		C[1][1] = (1 / x) * (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
		C[1][2] = (1 / x) * (-(A[0][0] * A[2][1] - A[2][0] * A[0][1]));
		C[2][0] = (1 / x) * (A[0][1] * A[1][2] - A[0][2] * A[1][1]);
		C[2][1] = (1 / x) * (-(A[0][0] * A[1][2] - A[1][0] * A[0][2]));
		C[2][2] = (1 / x) * (A[0][0] * A[1][1] - A[1][0] * A[0][1]);

		//transpose result into temporary array
		for (int j = 0; j < cols; j++)
		{
			for (int i = 0; i < rows; i++)
			{
				temp[j][i] = C[i][j];
			}
		}

		//print result
		for (int i = 0; i < rows; i++)
		{
			cout << "\t\t";
			for (int j = 0; j < cols; j++)
			{
				cout << temp[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "\t\tInverse not found" << endl;
	}
}

int main()
{
	int choice; //user's menu selection

	do
	{
		int A[10][10] = { 0 }, a_rows = 0, a_cols = 0;
		int B[10][10] = { 0 }, b_rows = 0, b_cols = 0;
		int C[10][10] = { 0 };

		choice = print_menu();
		switch (choice)
		{
		case 1:
			cout << "\tMatrix Addition (Using 2 Matrices)" << endl;
			cout << "\tBuilding Matrices..." << endl;
			get_dimensions(a_rows, a_cols);
			
			cout << "\tFilling 1st Matrix..." << endl;
			fill_matrix(A, a_rows, a_cols);
			cout << "\tPrinting 1st Matrix..." << endl;
			print_matrix(A, a_rows, a_cols);

			cout << "\tFilling 2nd Matrix..." << endl;
			fill_matrix(B, a_rows, a_cols);
			cout << "\tPrinting 2nd Matrix..." << endl;
			print_matrix(B, a_rows, a_cols);

			cout << "\tAdding Matrices..." << endl;
			add(A, B, C, a_rows, a_cols);
			break;
		case 2:
			cout << "\tMatrix Subtraction (Using 2 Matrices)" << endl;
			cout << "\tBuilding Matrices..." << endl;
			get_dimensions(a_rows, a_cols);

			cout << "\tFilling 1st Matrix (minuend)..." << endl;
			fill_matrix(A, a_rows, a_cols);
			cout << "\tPrinting 1st Matrix..." << endl;
			print_matrix(A, a_rows, a_cols);

			cout << "\tFilling 2nd Matrix (subtrahend)..." << endl;
			fill_matrix(B, a_rows, a_cols);
			cout << "\tPrinting 2nd Matrix..." << endl;
			print_matrix(B, a_rows, a_cols);

			cout << "\tSubtracting Matrices..." << endl;
			sub(A, B, C, a_rows, a_cols);
			break;
		case 3:
			cout << "\tMatrix Multiplication (Using 2 Matrices)" << endl;
			cout << "\tBuilding 1st Matrix..." << endl;
			get_dimensions(a_rows, a_cols);
			cout << "\tBuilding 2nd Matrix..." << endl;
			get_dimensions(b_rows, b_cols);

			if (a_cols == b_rows)
			{
				cout << "\tFilling 1st Matrix..." << endl;
				fill_matrix(A, a_rows, a_cols);
				cout << "\tPrinting 1st Matrix..." << endl;
				print_matrix(A, a_rows, a_cols);

				cout << "\tFilling 2nd Matrix..." << endl;
				fill_matrix(B, b_rows, b_cols);
				cout << "\tPrinting 2nd Matrix..." << endl;
				print_matrix(B, b_rows, b_cols);

				cout << "\tMultiplying Matrices..." << endl;
				mult(A, B, C, a_rows, a_cols, b_rows, b_cols);
			}
			else
			{
				cout << "\t\t\tColumns of 1st Matrix must equal rows of 2nd" << endl;
				cout << "\t\t\tDimensions provided are incompatible" << endl;
			}
			break;
		case 4:
			cout << "\tMatrix Transpose" << endl;
			cout << "\tBuilding Matrix..." << endl;
			get_dimensions(a_rows, a_cols);
			cout << "\tFilling Matrix..." << endl;
			fill_matrix(A, a_rows, a_cols);
			cout << "\tPrinting Matrix..." << endl;
			print_matrix(A, a_rows, a_cols);
			cout << "\tTransposing Matrix..." << endl;
			trans(A, C, a_rows, a_cols);
			break;
		case 5:
			cout << "\tMatrix Determinant" << endl;
			cout << "\tBuilding Matrix..." << endl;
			get_dimensions(a_rows, a_cols);

			if (a_rows == a_cols && a_rows == 3)
			{
				cout << "\tFilling Matrix..." << endl;
				fill_matrix(A, a_rows, a_cols);
				cout << "\tPrinting Matrix..." << endl;
				print_matrix(A, a_rows, a_cols);
				cout << "\tFinding Determinant..." << endl;
				cout << "\t\t" << det(A) << endl;
			}
			else
			{
				cout << "\t\t\tThis implementation only supports 3x3 Matrices" << endl;
				cout << "\t\t\tDimensions provided are incompatible" << endl;
			}
			break;
		case 6:
			cout << "\tMatrix Inversion" << endl;
			cout << "\tBuilding Matrix..." << endl;
			get_dimensions(a_rows, a_cols);

			if (a_rows == a_cols && a_rows == 3)
			{
				cout << "\tFilling Matrix..." << endl;
				fill_matrix(A, a_rows, a_cols);
				cout << "\tPrinting Matrix..." << endl;
				print_matrix(A, a_rows, a_cols);
				cout << "\tFinding Inverse..." << endl;
				inv(A, a_rows, a_cols);
			}
			else
			{
				cout << "\t\t\tThis implementation only supports 3x3 Matrices" << endl;
				cout << "\t\t\tDimensions provided are incompatible" << endl;
			}
			break;

		}
	} while (choice != 7);
}
