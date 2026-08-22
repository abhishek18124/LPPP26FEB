class Solution {
public:
	// time : O(n)
	// space: O(n) due to stack
	bool isValid(string s) {
		stack<char> stk;
		for (char ch : s) {
			switch (ch) {
			case '(':
			case '[':
			case '{': stk.push(ch); break;
			case ')': if (!stk.empty() and stk.top() == '(') stk.pop(); else return false; break;
			case ']': if (!stk.empty() and stk.top() == '[') stk.pop(); else return false; break;
			case '}': if (!stk.empty() and stk.top() == '{') stk.pop(); else return false; break;
			}
		}
		return stk.empty();
	}
};