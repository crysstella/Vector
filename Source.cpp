#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addNewName(vector<string> &names);
void findShortestAndLongest(vector<string> names);
int findIndex(vector<string> names, string nameFind);

int main()
{
	/*Create a program that allows the user to enter as many names as they want.
	Each of these names should be placed in a vector.
	Write a function findShortestAndLongest with a vector parameter that searches
	your vector and prints out the longest stringand the shortest string.
	Your main function should call this other function, passing the vector of names your
	user created*/

	vector<string> Names;
	string name;
	char option;

	do
	{
		cout << "(s)earch names that are longest and shortest, (a)dd new names, (q)uit" << endl;
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 'a':
			addNewName(Names);
			cout << "\n\n";
			break;
		case 's':
			findShortestAndLongest(Names);
			cout << "\n\n";
			break;
		default:
			break;
		}

	} while (option != 'q');
	return 0;
}

void addNewName(vector<string> &names)
{
	string newname;
	cout << "Please enter a new name: ";
	getline(cin, newname);

	for (int i = 0; i < newname.length(); i++)
	{
		if  ((ispunct(newname[i])) || (isdigit(newname[i])))
		{
			cout << "The name is invalid" << endl;
			return;
		}
	}

	int index = findIndex(names, newname);
	if (index == -1)
	{
		names.push_back(newname);
	}
	else
	{
		cout << "The name already exists";
	}
}

void findShortestAndLongest(vector<string> names)
{
	if (names.empty())
	{
		cout << "The collection of names is empty!";
	}
	else
	{
		//Find the number of max and min length.
		int MAX = names[0].length();
		int MIN = names[0].length();
		for (int i = 1; i < names.size(); i++)
		{
			if (names[i].length() > MAX)
			{
				MAX = names[i].length();
			}
			else
			{
				MIN = names[i].length();
			}
		}

		// Show largest names
		cout << "The longest name has length of " << MAX << ": " << endl;
		for (int i = 0; i < names.size(); i++)
		{
			if (names[i].length() == MAX)
			{
				cout << "-" << names[i] << endl;
			}
		}

		//Show shortest names
		cout << "The shortest name has length of " << MIN << ": " << endl;
		for (int i = 0; i < names.size(); i++)
		{
			if (names[i].length() == MIN)
			{
				cout << "-" << names[i] << endl;
			}
		}
	}
}

int findIndex(vector<string> names, string nameFind)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (names[i] == nameFind)
		{
			return i;
		}
	}
	return -1;
}