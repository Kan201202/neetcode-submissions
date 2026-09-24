class Solution {
public:

    // int khooshi(const vector<int>& heights, int start, int end){
    //     if(start>end)return 0;

    //     int mini = start;
    //     for(int i=start;i<=end;i++)if(heights[i]<heights[mini])mini=i;

    //     int curr = heights[mini]*(end-start+1);

    //     int left = khooshi(heights, start, mini-1);
    //     int right = khooshi(heights, mini+1, end);

    //     return max({curr, left, right});
    // }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        int khooshi = 0;

        for(int i=0;i<n;i++){
            if(st.empty())st.push(i);
            else{

                while(!st.empty() && heights[st.top()]>heights[i]){
                    int currh = heights[st.top()];
                    st.pop();

                    int leftBoundary = st.empty() ? -1 : st.top();
                    int currb = i-leftBoundary-1;

                    int currarea = currb*currh;
                    khooshi = max(khooshi, currarea);
                }
                st.push(i);
            }
        }

        while(!st.empty()) {
            int currh = heights[st.top()];
            st.pop();
            
            int leftBoundary = st.empty() ? -1 : st.top();
            int currb = n - leftBoundary - 1; 
            int currarea = currb * currh;
            
            khooshi = max(khooshi, currarea);
        }

        return khooshi;
    }
};
