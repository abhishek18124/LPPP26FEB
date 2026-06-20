#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	s1 = s1 + s2;

	cout << s1 << endl;

	string s3 = "xy";
	s3.push_back('z');

	cout << s3 << endl;

	string s4 = "hello";
	s4.pop_back();
	cout << s4 << endl;

	return 0;
}