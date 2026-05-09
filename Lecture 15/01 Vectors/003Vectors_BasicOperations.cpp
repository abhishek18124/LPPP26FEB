#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// 1. creating a vector using initialiser list

	vector<int> v = {1, 0, 2, 4, 3};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 2. reversing a vector

	// reverse(v.begin(), v.end());

	reverse(v.begin() + 2, v.begin() + 4);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 3. sorting a vector in the increasing order // nlogn // intro sort algorithm

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 4. sorting a vector in the decreasing order

	vector<int> v2 = {10, 1, 40, 50, 2};

	sort(v2.rbegin(), v2.rend());
	// sort(v2.begin(), v2.end(), greater<int>()); // greater<int>() is a function object / functor

	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}

	cout << endl;

	return 0;
}