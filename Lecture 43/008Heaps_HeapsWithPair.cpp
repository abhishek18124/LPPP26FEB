#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define pii pair<int, int>

int main() {


	// priority_queue<pii> maxHeap;

	priority_queue<pii, vector<pii>, greater<pii>> minHeap;

	// when you create a heap of pair<>, by default heap prop. works on the 1st memeber of the pair<>
	// and in case there is a tie, then second member is used

	minHeap.push({3, 4});
	minHeap.push({1, 5});
	minHeap.push({2, 1});
	minHeap.push({5, 6});
	minHeap.push({2, 3});

	while (!minHeap.empty()) {
		pair<int, int> p = minHeap.top();
		minHeap.pop();
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}