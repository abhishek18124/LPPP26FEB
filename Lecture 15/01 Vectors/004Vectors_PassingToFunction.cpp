#include<iostream>
#include<vector>

using namespace std;

void f(vector<int> v) {

	for (int i = 0; i < v.size(); i++) { // here, vector<> 'v' is passed by value so any changes done to 'v' within this function won't be reflected in the caller function i.e. main function
		v[i]++;
	}

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