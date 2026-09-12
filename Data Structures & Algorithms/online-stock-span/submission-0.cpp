class StockSpanner {
private:
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int khooshi = 1;
        while(!st.empty() && st.top().first <= price){
            khooshi = khooshi + st.top().second;
            st.pop();
        }
        st.push({price, khooshi});
        return khooshi;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */