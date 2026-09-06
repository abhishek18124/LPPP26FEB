/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    // priority_queue<int, vector<int>, greater<int>> minHeap;
    // for(int x : ropeLengths) {
    //     minHeap.push(x);
    // }

    // time : O(nlogn)
    // space: O(n) due to minHeap

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(),
            ropeLengths.end());

    int ans = 0; // to track miniumum overall cost

    while (minHeap.size() > 1) {
        int firstMin = minHeap.top(); minHeap.pop();
        int secondMin = minHeap.top(); minHeap.pop();
        int newRopeLength = firstMin + secondMin;
        ans += newRopeLength;
        minHeap.push(newRopeLength);
    }

    cout << ans << endl;


    return 0;
}