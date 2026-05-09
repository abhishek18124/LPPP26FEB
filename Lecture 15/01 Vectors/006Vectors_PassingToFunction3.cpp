#include<iostream>
#include<vector>

using namespace std;

void f(const vector<int>& v) { // here we are passing vector<> by const-ref which means we can access the vector<> using this ref but cannot modify the vector<> using this ref

	for (int i = 0; i < v.size(); i++) {
		// v[i]++; // error since we are working with a const ref
		cout << v[i] << " ";
	}

	cout << endl;

}

int main() {

	vector<int> v = {0, 1, 2, 3, 4};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	f(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;

}