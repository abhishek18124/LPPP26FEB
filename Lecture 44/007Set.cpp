#include<iostream>
// #include<unordered_set>
#include<set>

using namespace std;

int main() {

	// unordered_set<int> s;
	set<int> s;

	s.insert(2);
	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.insert(4);

	cout << (int)s.size() << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(2);

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.count(3)) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.count(2)) {
		cout << "2 is present" << endl;
	} else {
		cout << "2 is absent" << endl;
	}

	if (s.find(2) != s.end()) {
		cout << "2 is present" << endl;
	} else {
		cout << "2 is absent" << endl;
	}

	return 0;

}