#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	string str;
	cin >> str;

	int ans = 0;
	set<char> s;

	// time : O(nlog(set size))
	// space: O(set size)

	for (char ch : str) {
		if (s.find(ch) != s.end()) {
			ans += 2;
			s.erase(ch);
		} else {
			s.insert(ch);
		}
	}

	if (!s.empty()) {
		ans++;
	}

	cout << ans << endl;

	return 0;

}