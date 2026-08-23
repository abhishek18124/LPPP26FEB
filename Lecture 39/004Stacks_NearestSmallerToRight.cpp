#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nsr(const vector<int>& A) {

	stack<int> stk; // monotonic stack // <index>

	int n = (int)A.size();
	vector<int> ans;

	// time : O(n)
	// space: O(n) due to monotonic stack

	for (int i = n - 1; i >= 0; i--) {
		// find the index of nsr of A[i] using monotonic stack
		while (!stk.empty() and A[stk.top()] >= A[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			// there is no smaller element to the right of A[i]
			ans.push_back(n);
		} else {
			// whatever element is at the top of the stack is the index of nearest smaller element to the right of A[i]
			ans.push_back(stk.top());
		}
		stk.push(i);
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> A = {2, 5, 1, 3, 6, 4, 0};

	vector<int> ans = nsr(A);
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;


	return 0;
}