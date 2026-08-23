class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int i;
    StockSpanner() {
        i = 0;
    }

    int next(int price) {
        while (!stk.empty() and stk.top().first <= price) {
            stk.pop();
        }
        int j;
        if (stk.empty()) {
            j = -1;
        } else {
            j = stk.top().second;
        }
        stk.push({price, i});
        int span = i - j;
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */