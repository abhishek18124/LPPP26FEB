#include<iostream>

using namespace std;

int main() {

	char grade;
	cin >> grade;

	// you can switch char or int

	switch (grade) {

	case 'A': cout << "v.good" << endl; break;
	case 'B': cout << "good" << endl; break;
	case 'C': cout << "avg." << endl; break;
	case 'D': cout << "poor" << endl; break;
	case 'E': cout << "v.poor" << endl; break;
	case 'F': cout << "fail" << endl; break;
	default: cout << "invalid" << endl; break;

	}

	cout << "you are outside the switch block" << endl;

	return 0;
}