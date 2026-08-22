#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

// time : O(n)
// space: O(n)

void insertAtBottom(stack<int>& s, int data) {

	// base case
	if (s.empty()) {
		s.push(data);
		return;
	}

	// recursive case

	int topVal = s.top();
	s.pop();

	insertAtBottom(s, data);

	s.push(topVal);

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	int data = 0;

	insertAtBottom(s, data);

	print(s);

	return 0;
}