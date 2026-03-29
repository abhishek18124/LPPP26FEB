#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// print i stars for the ith row

		for (int j = 1; j <= i; j++) {
			cout << "*";
		}

		cout << endl;

	}

	return 0;

}