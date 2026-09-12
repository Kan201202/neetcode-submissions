class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            int val = asteroids[i];
            bool khooshi = false;

            while(!st.empty() && st.top()>0 && val<0){
                if(st.top() < abs(val))st.pop();
                else if(st.top()==abs(val)){
                    st.pop();
                    khooshi = true;
                    break;
                }
                else{
                    khooshi = true;
                    break;
                }
            }

            if(!khooshi)st.push(val);
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};