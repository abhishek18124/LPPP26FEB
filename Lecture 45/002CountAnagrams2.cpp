#include<iostream>
#include<map>

using namespace std;

int main() {

	string s = "cbaebabacd";
	string t = "abc";

	int n = s.size();
	int k = t.size(); // size of the window

	int cnt = 0; // to store the cnt of anagrams of 't' in 's'

	map<char, int> tFreqMap; // to store a mapping  b/w characters
	// present in 't' & their frequencies
	for (int i = 0; i < k; i++) {
		tFreqMap[t[i]]++;
	}

	// for (auto [ch, freq] : tFreqMap) {
	// 	cout << ch << " " << freq << endl;
	// }

	// cout << endl;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	map<char, int> wFreqMap; // to store a mapping between characters
	// present in window & their frequencies

	// build the frequency map for the 1st window

	while (j < k) {
		wFreqMap[s[j]]++;
		j++;
	}


	// for (auto [ch, freq] : tFreqMap) {
	// 	cout << ch << " " << freq << endl;
	// }

	// cout << endl;

	// check if the window is an anagram of 't'

	if (tFreqMap == wFreqMap) cnt++;

	// cout << cnt << endl;

	// build the frequency map for the remaining window

	while (j < n) {
		// slide the window
		wFreqMap[s[i]]--;
		if (wFreqMap[s[i]] == 0) {
			wFreqMap.erase(s[i]);
		}
		i++;
		wFreqMap[s[j]]++;
		j++;

		// for (auto [ch, freq] : wFreqMap) {
		// 	cout << ch << " " << freq << endl;
		// }

		// cout << endl;

		// update the answer
		if (tFreqMap == wFreqMap) cnt++;
	}

	cout << cnt << endl;

	return 0;
}