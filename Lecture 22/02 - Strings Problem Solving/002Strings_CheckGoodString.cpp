#include<iostream>
#include<string>

using namespace std;

// time : O(n)

bool isGoodString(const string& str) {

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false;
		}
	}

	return true; // str is good string

}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;
}