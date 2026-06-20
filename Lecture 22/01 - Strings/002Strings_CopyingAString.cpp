#include<iostream>
#include<string>

using namespace std;

int main() {

	// int x = 10;

	// int y;

	// y = 10;

	// int z = x;

	string s = "coding";

	string t = s;

	string w;

	w = s;

	cout << s << endl;
	cout << t << endl;
	cout << w << endl;

	t[0] = 'd';

	cout << s << endl;
	cout << t << endl;

	string& e = s;

	e[0] = 'a';

	cout << s << endl;

	return 0;
}