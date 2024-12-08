//Tamis Amor Maniago
//CIS 1202 Exceptions
//December 8, 2024
//Program tests if characters are valid and in range.
//If not, exception will be thrown.

#include <iostream>

using namespace std;

//Exception for invalid character
class invalidCharacterException : public exception {
public:
	const char* what() const noexcept override {
		return "Error: Character is not a letter.";
	}
};

//Exception for invalid range
class invalidRangeException : public exception {
public:
	const char* what() const noexcept override {
		return "Error: Character is not in range. (A-Z, a-z)";
	}
};

//Function prototype
char character(char, int);

int main() {

	//Test #1 - return 'b'
	try
	{
		cout << "Character: " << character('a', 1) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	//Test #2 - throws invalidRangeException
	try {
		cout << "Character: " << character('a', -1) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	//Test #3 - return "Y'
	try {
		cout << "Character: " << character('Z', -1) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	//Test #4 - throws invalidCharacterException
	try {
		cout << "Character: " << character('?', 5) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
		return 0;
}

//Function for characters
char character(char start, int offset){

	if (!isalpha(start)) {
		throw invalidCharacterException();
	}
	char result = start + offset;

	if ((isupper(start) && (result < 'A' || result > 'Z')) ||
		(islower(start) && (result < 'a' || result > 'z'))) {
		throw invalidRangeException();
	}
	return result;
}

