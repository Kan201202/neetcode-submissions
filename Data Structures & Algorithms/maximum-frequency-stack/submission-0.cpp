class FreqStack {
private:
    unordered_map<int,int> freq;
    unordered_map<int, stack<int>> group;
    int maxfreq;
public:
    FreqStack() {
        maxfreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        int curr = freq[val];
        if(curr>maxfreq)maxfreq=curr;

        group[curr].push(val);
    }
    
    int pop() {
        int val = group[maxfreq].top();
        group[maxfreq].pop();

        freq[val]--;

        if(group[maxfreq].empty())maxfreq--;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */