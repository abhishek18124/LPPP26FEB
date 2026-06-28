class Solution {
public:

    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {
        int cnt = 0;
        for (int d : bloomDay) {
            if (d <= timeLimit) {
                // current flower is bloomed so pick it
                cnt++;
                if (cnt == k) {
                    // we've managed to make a bouquet using k picked flowers
                    m--;
                    cnt = 0;
                    if (m == 0) {
                        // we've managed to make m bouquets of k adjacent flowers
                        return true;
                    }
                }
            } else {
                // throw away the flowers picked as they can no longer be used
                cnt = 0;
            }
        }

        // we could not manage to make m bouquets of k adjacent flowers
        return false;
    }

    // time : n for min, n for max, 30n for bs ~ O(n)
    // space: O(1)

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (s <= e) { // log(e-s) // log(10^9 - 1) ~ 30 iterations
            int mid = s + (e - s) / 2;
            // can I make 'm' bouquets of 'k' adjacent
            // flowers in 'mid' no. of days ?
            if (f(bloomDay, m, k, mid)) {
                // yes, you can make 'm' bouquets
                // of 'k' adj. flowers in 'mid'
                // days
                ans = mid;
                e = mid - 1;
            } else {
                // no, you cannot make 'm' bouquets
                // of 'k' adj. flowers in 'mid'
                // days
                s = mid + 1;
            }
        }

        return ans;
    }
};