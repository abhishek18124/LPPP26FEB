#include<iostream>
#include<vector>

using namespace std;

// time : O(n^2)

void generatePairs(const vector<int>& arr, int n) {

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << arr[i] << " " << arr[j] << "\n";
		}
		cout << "\n";
	}

}

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

	generatePairs(arr, n);

	return 0;
}