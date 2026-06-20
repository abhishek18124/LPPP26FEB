#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "bxadzy";

	// sort(s.begin(), s.end());
	sort(s.rbegin(), s.rend());

	cout << s << endl;

	return 0;
}