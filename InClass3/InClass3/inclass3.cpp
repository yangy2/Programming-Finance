//Yilin Yang
//Programming Finance InClass 3

#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	const int students = 20;
	const int candidates = 5;
	int votes[students];
	int results[candidates];

	cout << "Vote for the next apprentice!" << endl;
	cout << "There are 5 candidates to choose from!" << endl;
	cout << "Enter 1, 2, 3, 4, or 5 to vote!\n" << endl;

	for (int i = 0; i < students; i++)
	{
		do
		{
			cout << "What is your vote, Student " << i + 1 << "?" << endl;
			cin >> votes[i];
			if (cin.fail() || votes[i] < 1 || votes[i] > 5) //Error checking if vote is not valid
			{
				cout << "Please cast a valid vote: 1, 2, 3, 4, or 5\n" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			}
		} while (votes[i] < 1 || votes[i] > 5); //Repeat if vote was invalid
	}

	//Set vote count for each candidate to zero
	for (int i = 0; i < candidates; i++)
	{
		results[i] = 0;
	}
	//count votes for each candidate
	for (int i = 0; i < students; i++)
	{
		results[votes[i] - 1]++;
	}
	//Print vote count
	cout << "****** RESULTS ******" << endl;
	for (int i = 0; i < candidates; i++)
	{
		cout << "Candidate " << i + 1 << ": " << results[i] << " votes" << endl;
	}
	cout << "*********************" << endl;

	int winner = 0;
	bool tie_flag = false;
	int tie[candidates];

	//Check who has the most votes
	for (int i = 1; i < candidates; i++)
	{
		if (results[i] > results[winner]) winner = i;
	}

	//Check if there is a tie
	for (int i = 1; i < candidates; i++)
	{
		//Identify which candidates tied
		if (results[i] == results[winner] && i != winner)
		{
			tie_flag = true;
			tie[winner] = 1;
			tie[i] = 1;
		}
	}

	//Anounce the winner
	if (!tie_flag) cout << "The winner is Candidate " << winner + 1 << endl;
	else
	{
		cout << "There is a tie between:" << endl;
		for (int i = 0; i < candidates; i++)
		{
			if (tie[i] == 1) cout << "Candidate " << i + 1 << endl;
		}
		cout << "There is no winner..." << endl;
	}
	_getch();

}
