#include<iostream>

using namespace std;

// time : n + n + 26 = 2n + 26 ~ O(n)
// space: 26 + 26 ~ O(1)

bool isAnagram(char s1[], char s2[]) {

	// 1. build a freqMap for s1[]
	int freqMap1[26] = {0};
	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		int idx = ch - 'a';
		freqMap1[idx]++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << freqMap1[i] << " ";
	// }

	// cout << endl;

	// 2. build a freqMap for s2[]
	int freqMap2[26] = {0};
	for (int i = 0; s2[i] != '\0'; i++) {
		freqMap2[s2[i] - 'a']++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << freqMap2[i] << " ";
	// }

	// cout << endl;

	// 3. compare both the freqMaps
	for (int i = 0; i < 26; i++) {
		if (freqMap1[i] != freqMap2[i]) {
			// s1 and s2 cannot be anagrams
			return false;
		}
	}

	// s1 and s2 are anagrams
	return true;

}

int main() {

	char s1[] = "aabbbc";
	char s2[] = "aabbcc";

	isAnagram(s1, s2) ? cout << "anagram" << endl : cout << "not anagram" << endl;

	return 0;
}