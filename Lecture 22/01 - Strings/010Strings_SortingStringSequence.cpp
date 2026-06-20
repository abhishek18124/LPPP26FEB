#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool cmp(string& a, string& b) {
	if (a.size() < b.size()) {
		return true;
	} else {
		return false;
	}
}

int main() {

	vector<string> names;

	names.push_back("devansh");
	names.push_back("pranav");
	names.push_back("arpn");
	names.push_back("ujwal");

	sort(names.begin(), names.end(), cmp);

	for (string n : names) {
		cout << n << endl;
	}

	return 0;
}