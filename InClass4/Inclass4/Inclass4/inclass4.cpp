//Yilin Yang
//Programming Finance Inclass 4

#include <iostream>
#include <string>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//Count instances of character "c" in string "word"
std::size_t search(string word, string c)
{
	string::size_type position = word.find(c); //find character's position in string
	if (position == string::npos) return 0; //if at the end of the string, 0 instances
	else return (1 + search(word.substr(position + 1), c)); //else search again with shortened string
}

int main()
{
	string word;
	string c;

	cout << "Enter a string: ";
	getline(cin, word);
	cout << "Your string is: " << word << endl;

	int length;
	do
	{
		cout << "Enter a character: ";
		getline(cin, c);

		length = c.size();
		if (length != 1) cout << "Please enter 1 character" << endl;
		else cout << "Your character is: " << c << endl;

	} while (length != 1);

	int count = search(word, c);
	cout << "Found " << count << " instance(s) of " << c << " in " << word << endl;

	_getch();
}