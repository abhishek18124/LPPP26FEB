class Solution {
public:
	// time : O(n)
	// space: O(n) due to stack
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> stk;
		for (int ast : asteroids) {
			if (ast < 0 and !stk.empty() and stk.top() > 0) {
				// collisions will happen
				bool flag = true; // assume ast will survive collisions
				while (!stk.empty() and stk.top() > 0) {
					if (abs(ast) > stk.top()) {
						stk.pop();
					} else if (abs(ast) < stk.top()) {
						flag = false;
						break;
					} else {
						// abs(ast) equal to stk.top()
						flag = false;
						stk.pop();
						break;
					}
				}
				if (flag) {
					// ast has indeed survived all the collisions
					stk.push(ast);
				}
			} else {
				stk.push(ast);
			}
		}

		vector<int> ans;
		while (!stk.empty()) {
			ans.push_back(stk.top());
			stk.pop();
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};