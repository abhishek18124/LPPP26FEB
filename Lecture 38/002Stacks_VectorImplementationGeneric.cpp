#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {

	vector<T> v; // internal representation of the stack

public :

	void push(T val) {
		v.push_back(val);
	}

	void pop() {
		if (empty()) {
			return;
		}
		v.pop_back();
	}

	int size() {
		return v.size();
	}

	T top() {
		return v.back(); // v[v.size()-1]
	}

	bool empty() {
		return v.empty();
	}

};

int main() {

	stack<string> s;

	s.push("ABC");
	s.push("DEF");
	s.push("GHI");

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;


	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "empty : " << s.empty() << endl;

	return 0;

}