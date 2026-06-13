// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101];

	// cin >> str;

	cin.getline(str, 5, '$');

	// by default '\n' is the delimiting character

	cout << str << endl;

	return 0;
}