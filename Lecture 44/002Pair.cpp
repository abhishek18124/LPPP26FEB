#include<iostream>

using namespace std;

int main() {

	pair<int, int> p1 = {1, 2};

	cout << p1.first << " " << p1.second << endl;

	pair<string, string> p2 = {"india", "new delhi"};

	cout << p2.first << " " << p2.second << endl;

	pair<int, int> p3;

	cin >> p3.first >> p3.second;

	cout << p3.first << " " << p3.second << endl;

	return 0;

}