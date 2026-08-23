#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nsl(const vector<int>& A) {

	stack<int> stk; // monotonic stack // <index>

	int n = (int)A.size();
	vector<int> ans;

	// time : O(n)
	// space: O(n) due to monotonic stack

	for (int i = 0; i < n; i++) {
		// find the index of nsl of A[i] using monotonic stack
		while (!stk.empty() and A[stk.top()] >= A[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			// there is no smaller element to the left of A[i]
			ans.push_back(-1);
		} else {
			// whatever element is at the top of the stack is the index of nearest smaller element to the left of A[i]
			ans.push_back(stk.top());
		}
		stk.push(i);
	}

	return ans;

}

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

	vector<int> h = {2, 1, 5, 6, 2, 3};
	int n = (int)h.size();

	vector<int> nslIndex = nsl(h); // O(n)
	vector<int> nsrIndex = nsr(h); // O(n)

	int maxSoFar = 0;

	for (int i = 0; i < n; i++) { // O(n)
		// find the bestWidth for h[i]
		int bestWidth = nsrIndex[i] - nslIndex[i] - 1;
		int bestArea = h[i] * bestWidth;
		maxSoFar = max(maxSoFar, bestArea);
	}

	cout << maxSoFar << endl;

	// time : O(n) // space : O(n) due to monotonic stack in nsl and nsr

	return 0;
}