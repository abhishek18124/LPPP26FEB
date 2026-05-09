/*

	Vectors Part II

	How to create a vector ?
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a vector ?
	    > use vector::insert
	      > single element
	      > fill
	      > range
	      > initialiser list
	How to remove elements from a vector ?
	    > use vector::erase
	      > single element
	      > range

	How to sort a vector ?
      > use built-in comparator
      > use user-defined comparator
      > pass in reverse order

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// fill constructor

	vector<int> v(5); // or vector<int> v(5, 100); // creates a vector<> of size 5 initialised with 0
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "size = " << v.size() << endl; // 5
	cout << "capacity = " << v.capacity() << endl; // 5

	v.push_back(1);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	cout << "size = " << v.size() << endl; // 6
	cout << "capacity = " << v.capacity() << endl; // 10

	vector<int> v2 = v; // or vector<int> v2(v); // copy constructor

	cout << "v2.size = " << v2.size() << endl;
	cout << "v2.capacity = " << v2.capacity() << endl;

	vector<int> v3;
	v3 = v; // copy assignment operator

	// range constructor

	vector<int> v4 = {1, 2, 3, 4, 5};

	vector<int> v5(v4.begin() + 2, v4.begin() + 4); // [2, 4)

	// [2, 4)

	for (int i = 0; i < v5.size(); i++) {
		cout << v5[i] << " ";
	}
	cout << endl;

	vector<int> v6(v4.begin() + 1, v4.begin() + 4);
	for (int i = 0; i < v6.size(); i++) {
		cout << v6[i] << " ";
	}
	cout << endl;

	return 0;
}






