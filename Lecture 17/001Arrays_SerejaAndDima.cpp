#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int serejaScore = 0;
	int dimaScore = 0;

	bool serejaTurn = true;

	int i = 0;
	int j = n - 1;

	while (i <= j) {

		if (serejaTurn) {
			// it is sereja's turn
			if (a[i] > a[j]) {
				serejaScore += a[i];
				i++;
			} else {
				serejaScore += a[j];
				j--;
			}
			serejaTurn = false;
		} else {
			// it is dima's turn
			if (a[i] > a[j]) {
				dimaScore += a[i];
				i++;
			} else {
				dimaScore += a[j];
				j--;
			}
			serejaTurn = true;
		}

	}

	cout << serejaScore << " " << dimaScore << '\n';

	return 0;
}