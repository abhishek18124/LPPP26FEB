#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	n > 0 ? cout << "positve" << endl : n < 0 ? cout << "negative" << endl : cout << "zero" << endl;

	return 0;
}