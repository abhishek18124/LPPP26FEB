#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcabc";

	cout << s.find("ca") << endl;
	cout << s.rfind("ca") << endl;

	cout << s.find("xyz") << endl;
	cout << string::npos << endl;

	if (string::npos == -1) {
		cout << "yes" << endl;
	}

	return 0;
}