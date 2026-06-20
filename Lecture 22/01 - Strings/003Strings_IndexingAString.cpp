#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "coding blocks";

	// cout << s[0] << endl;
	// cout << s[1] << endl;

	for (int i = 0; i < (int)s.size(); i++) {
		cout << s[i] << endl;
	}

	// for (int i = 0; s[i] != '\0'; i++) {
	// 	cout << s[i] << endl;
	// }


	return 0;
}