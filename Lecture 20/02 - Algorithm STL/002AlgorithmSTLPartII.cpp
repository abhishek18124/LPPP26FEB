#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// return true if you want a to be ordered before b in the sorted output otherwise return false
bool cmp(string a, string b) {
	// int lenA = a.size();
	// int lenB = b.size();
	// if (lenA < lenB) {
	// 	return true;
	// } else {
	// 	return false;
	// }

	return a.size() > b.size();

}

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence in the decreasing order

	// 1. using a customer comparator

	vector<string> names;

	names.push_back("devansh");
	names.push_back("dev");
	names.push_back("arpan");
	names.push_back("yash");
	names.push_back("pranav");

	// sort(names.begin(), names.end());
	// sort(names.rbegin(), names.rend());
	// sort(names.begin(), names.end(), greater<string>());

	sort(names.begin(), names.end(), cmp);

	for (string n : names) {
		cout << n << endl;
	}

	// 2. using greater<T>() function object / functor

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// vector<int> v = {10, 40, 30, 50, 20};
	// sort(v.rbegin(), v.rend());
	// sort(v.begin(), v.end(), greater<int>());
	// for (int i = 0; i < (int)v.size(); i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << endl;

	return 0;
}
