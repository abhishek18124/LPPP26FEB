/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v; // internal repr. of minHeap

	// [HW] impl. heapify iteratively

	void heapify(int i) {

		// fix min heap prop. at index i

		int minIdx = i;
		int leftIdx = 2 * i + 1;

		if (leftIdx < (int)v.size() and v[leftIdx] < v[minIdx]) {
			minIdx = leftIdx;
		}

		int rightIdx = 2 * i + 2;
		if (rightIdx < (int)v.size() and v[rightIdx] < v[minIdx]) {
			minIdx = rightIdx;
		}

		if (minIdx != i) {
			swap(v[minIdx], v[i]);
			heapify(minIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx = (int)v.size() - 1;
		int parentIdx = (childIdx - 1) / 2;

		while (childIdx != 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = (childIdx - 1) / 2;
		}


	}

	// time : O(logn)

	void pop() {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		heapify(0); // fix the heap prop. at index x
	}

	// time : O(1)

	int top() {
		return v[0];
	}

	// time : O(1)

	int size() {
		return v.size();
	}

	// time : O(1)

	bool empty() {
		return v.empty();
	}

};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}



