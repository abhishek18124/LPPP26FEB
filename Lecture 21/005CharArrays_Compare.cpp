#include<iostream>
#include<cstring>

using namespace std;

// time : O(min(m, n))
// m is the length of s1
// n is the length of s2

int stringCompare(char s1[], char s2[]) {

	int i = 0;
	int j = 0;

	while (s1[i] != '\0' and s2[j] != '\0') {
		if (s1[i] == s2[j]) {
			i++;
			j++;
		} else if (s1[i] > s2[j]) {
			// s1 > s2
			return 1;
		} else {
			// s1[i] < s2[j]
			return -1; // s1 < s2
		}
	}

	if (s1[i] == '\0' and s2[j] == '\0') {
		// s1 is equal to s2
		return 0;
	} else if (s1[i] == '\0' and s2[j] != '\0') {
		// length of s1 < length of s2
		// s1 < s2
		return -1;
	} else {
		// s1[i] != '\0' and s2[j] == '\0'
		// length of s1 > length of s2
		// s1 > s2
		return 1;
	}

}

int main() {

	char s1[] = "agc";
	char s2[] = "aec";

	// int ans = stringCompare(s1, s2);
	int ans = strcmp(s1, s2);

	cout << ans << endl;;

	if (ans == 0) {
		cout << s1 << " is equal to " << s2 << endl;
	} else if (ans > 0) {
		cout << s1 << " > " << s2 << endl;
	} else {
		// ans < 0
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}