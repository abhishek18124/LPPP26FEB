#include<iostream>

using namespace std;

int main() {

	char grade;
	cin >> grade;

	if (grade == 'A') {
		cout << "v.good" << endl;
	} else if (grade == 'B') {
		cout << "good" << endl;
	} else if (grade == 'C') {
		cout << "avg." << endl;
	} else if (grade == 'D') {
		cout << "poor" << endl;
	} else if (grade == 'E') {
		cout << "v.poor" << endl;
	} else if (grade == 'F') {
		cout << "fail" << endl;
	} else {
		cout << "invalid" << endl;
	}

	cout << "you are outside the if-else-if block" << endl;

	return 0;
}