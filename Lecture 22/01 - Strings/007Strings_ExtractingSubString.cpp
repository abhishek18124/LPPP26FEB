#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";

	cout << s.substr(1, 3) << endl;
	cout << s.substr(4, 2) << endl;
	cout << s.substr(3) << endl;

	string t = s.substr(1, 2);
	cout << t << endl;
	cout << (int)t.size() << endl;

	return 0;
}