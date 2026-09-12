class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> khooshi(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!st.empty()){
                int tp = temperatures[st.top()];
                int curr = temperatures[i];

                if(tp>=curr){
                    st.push(i);
                }
                else{
                    while(!st.empty() && curr> temperatures[st.top()]){
                        int j = st.top();
                        st.pop();
                        khooshi[j] = i-j;
                    }
                    st.push(i);
                }
            }
            else{
                st.push(i);
            }
        }
        return khooshi;
    }
};
