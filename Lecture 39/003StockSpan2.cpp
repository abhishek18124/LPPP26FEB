#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> stockSpan(const vector<int>& A) {

	stack<int> stk; // monotonic stack // <index>

	int n = (int)A.size();
	vector<int> ans;

	// time : O(n)
	// space: O(n) due to monotonic stack

	for (int i = 0; i < n; i++) {
		// find the index of ngl of A[i] using monotonic stack
		while (!stk.empty() and A[stk.top()] <= A[i]) {
			stk.pop();
		}
		int j;
		if (stk.empty()) {
			// there is no greater element to the left of A[i]
			j = -1;
		} else {
			// whatever element is at the top of the stack is the nearest greater element to the left of A[i]
			j = stk.top();
		}
		ans.push_back(i - j);
		stk.push(i);
	}

	return ans;

}


int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85};

	vector<int> ans = stockSpan(A);
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;


	return 0;
}