#include<iostream>
#include<vector>

using namespace std;

void f(vector<int>& v) {

	for (int i = 0; i < v.size(); i++) { // here, we are passing vector<> 'v' by reference therefore changes done to 'v' within this function will be reflected in the caller fn i.e. main function
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