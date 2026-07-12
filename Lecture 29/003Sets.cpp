/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	// set<int, greater<int>> s;
	set<int> s;

	cout << s.size() << endl;
	cout << s.empty() << endl;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // ignored

	cout << "size : " << s.size() << endl; // 5

	s.erase(5); // 5 is erased
	s.erase(6); // ignored

	cout << "size : " << s.size() << endl; // 4

	// for (auto it = s.begin(), end = s.end(); it != end; it++) {
	// 	cout << *it << " ";
	// }

	// cout << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.find(5) != s.end()) {
		cout << "5 is present" << endl;
	} else {
		cout << "5  is absent" << endl;
	}

	if (s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}


	s.clear();

	cout << "size : " << s.size() << endl;
	cout << s.empty() << endl;

	return 0;
}