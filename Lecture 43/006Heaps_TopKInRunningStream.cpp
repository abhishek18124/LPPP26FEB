/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

using namespace std;

#define pqmin priority_queue<int, vector<int>, greater<int>>

void print(pqmin minHeap) {
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k = 3;
    pqmin minHeap;

    int val;

    // assume 1st k values in the stream  are not -1, so push them directly into minHeap
    for (int i = 0; i < k; i++) {
        cin >> val;
        minHeap.push(val);
    }

    while (true) {

        cin >> val;
        if (val == -1) {
            print(minHeap);
        } else {
            if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }
        }

    }


    return 0;
}