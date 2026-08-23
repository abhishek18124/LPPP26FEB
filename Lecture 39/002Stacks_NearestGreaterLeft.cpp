#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> ngl(const vector<int>& A) {

	stack<int> stk; // monotonic stack

	int n = (int)A.size();
	vector<int> ans;

	// time : O(n)
	// space: O(n) due to monotonic stack

	for (int i = 0; i < n; i++) {
		// find the ngl of A[i] using monotonic stack
		while (!stk.empty() and stk.top() <= A[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			// there is no greater element to the left of A[i]
			ans.push_back(-1);
		} else {
			// whatever element is at the top of the stack is the nearest greater element to the left of A[i]
			ans.push_back(stk.top());
		}
		stk.push(A[i]);
	}

	return ans;

}

int main() {

	vector<int> A = {5, 2, 0, 4, 1, 3, 6};

	vector<int> ans = ngl(A);
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}