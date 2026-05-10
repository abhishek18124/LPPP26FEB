#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = (int)arr.size();

	vector<int> pSum(n);

	pSum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << pSum[i] << " ";
	}

	cout << "\n";

	return 0;
}