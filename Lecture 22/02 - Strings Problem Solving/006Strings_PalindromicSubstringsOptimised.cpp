#include<iostream>
#include<string>

using namespace std;

int countPalindromicSubstrings(const string& s) {

	int n = (int)s.size();
	int cnt = 0; // to track the no. of palindromic substrings in the given string

	// 1. find the count of odd len palindromic substrings

	for (int i = 0; i < n; i++) {

		// find the no. of odd len palindromic substrings around s[i]

		int j = 0;
		while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) {
			cnt++;
			j++;
		}

	}

	// 2. find the count of even len palindromic substring

	for (double i = 0.5; i < n; i++) {

		// find the no. of even len palindromic substrings around ith center

		double j = 0.5;
		while (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) {
			cnt++;
			j++;
		}

	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}