class MyQueue {

private:
stack<int> st;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> helper;

        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }

        st.push(x);

        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }

    }
    
    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.size()==0)return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */