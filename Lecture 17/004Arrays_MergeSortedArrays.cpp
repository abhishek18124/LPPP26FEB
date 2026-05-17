#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a = {10, 30, 50, 70};
	vector<int> b = {20, 40, 60};

	int n = a.size();
	int m = b.size();

	vector<int> c(n + m);

	int i = 0; // to iterate over a[]
	int j = 0; // to iterate over b[]
	int k = 0; // to iterate over c[]

	while (i <= n - 1 and j <= m - 1) {

		if (a[i] <= b[j]) {
			c[k] = a[i];
			i++; k++;
		} else {
			c[k] = b[j];
			j++; k++;
		}

	}

	while (i <= n - 1) {
		c[k] = a[i];
		i++; k++;
	}

	while (j <= m - 1) {
		c[k] = b[j];
		j++; k++;
	}

	for (int num : c) {
		cout << num << " ";
	}

	cout << '\n';

	for (int i = 0; i < n + m; i++) {
		cout << c[i] << " ";
	}

	cout << '\n';

	// time : O(n+m)

	return 0;
}

