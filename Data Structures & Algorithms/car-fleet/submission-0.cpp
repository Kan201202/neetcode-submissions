class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<double> time(n);
        for(int i=0;i<n;i++){
            time[i] = (double)(target-position[i])/speed[i];
        }

        vector<pair<int,double>> abc(n);
        for(int i=0;i<n;i++){
            abc[i].first = position[i];
            abc[i].second = time[i];
        }
        sort(abc.begin(), abc.end());

        stack<double> st;
        st.push(abc[n-1].second);

        for(int i=n-2;i>=0;i--){
            if(abc[i].second > st.top()){
                st.push(abc[i].second);
            }
        }

        return st.size();

    }
};
