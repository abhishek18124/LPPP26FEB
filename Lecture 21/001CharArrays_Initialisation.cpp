#include<iostream>

using namespace std;

int main() {

	// when you initialise a string using initialiser list then we must add \0 ourselves.

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};

	cout << str << endl;

	// when you initialise a string using string literal then \0 is added automatically

	char str2[] = "coding";

	cout << str2 << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << "\n";
	}

	cout << endl;

	return 0;
}