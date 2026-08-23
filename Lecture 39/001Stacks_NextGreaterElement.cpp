#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> ngr(const vector<int>& A) {

	stack<int> stk; // monotonic stack

	int n = (int)A.size();
	vector<int> ans;

	// time : O(n)
	// space: O(n) due to monotonic stack

	for (int i = n - 1; i >= 0; i--) {
		// find the ngr of A[i] using monotonic stack
		while (!stk.empty() and stk.top() <= A[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			// there is no greater element to the right of A[i]
			ans.push_back(-1);
		} else {
			// whatever element is at the top of the stack is the nearest greater element to the right of A[i]
			ans.push_back(stk.top());
		}
		stk.push(A[i]);
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = ngr(A);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}