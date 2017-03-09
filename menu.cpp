/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Lab 5 - Predator vs Prey
***************************/

#include "menu.h"

int getInt(string prompt) {
	float input;
	int num;
	bool isInt = false;

	do {
		cout << prompt;
		cin >> input;
		num = input;
		if (cin.good() && num > 0 && num == input) {
			isInt = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isInt);

	return num;
}

int getIntLimited(string prompt, int min, int max) {
	int num;
	bool isInt = false;

	do {
		cout << prompt << " (Pick between " << min << " and " << max << "): ";
		cin >> num;
		if (cin.good() && num >= min && num <= max) {
			isInt = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isInt);

	return num;
}

//This function is for testing on Windows OS and will not be used on FLIP
void clearScreenWindows() {
	system("CLS");
}

void clearScreenUnix() {
	cout << "\033[2J\033[1;1H" << endl;
}

void enterToContinue() {
	cout << "Press Enter to Continue (hold to speed through)" << flush;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

bool yesOrNo(string prompt) {
	string ans;
	bool isStr = false;

	do {
		cout << prompt;
		getline(cin, ans);
		if (ans == "y" || ans == "Y" || ans == "n" || ans == "N")
			isStr = true;
	} while (!isStr);

	if (ans == "y" || ans == "Y")
		return true;
	else if (ans == "n" || ans == "N")
		return false;
}

string getString(string prompt) {
	string ans;
	cout << prompt;
	getline(cin, ans);
	string fixedAns = removeWhitespace(ans, " \t");
	return fixedAns;
}

double getDouble(string prompt) {
	double num;
	bool isDouble = false;

	do {
		cout << prompt;
		cin >> num;
		if (cin.good() && num > 0) {
			isDouble = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isDouble);

	return num;
}

string removeWhitespace(string str, string space)
{
	int begin = str.find_first_not_of(space);
	int end = str.find_last_not_of(space);
	int length = end - begin + 1;

	return str.substr(begin, length);
}