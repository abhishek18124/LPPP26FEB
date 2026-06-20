#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abc";
	string t = "adc";

	if (s == t) {
		cout << "equal" << endl;
	} else if (s > t) {
		cout << s << " > " << t << endl;
	} else {
		cout << s << " < " << t << endl;
	}

	return 0;
}