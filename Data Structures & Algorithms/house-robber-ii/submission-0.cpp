class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n+1,0), dp2(n+1,0);
        dp1[1]=nums[0];
        if(n>=2)dp1[2]=nums[0];
        for(int i=3;i<=n-1;i++){
            dp1[i]=max(nums[i-1]+dp1[i-2], dp1[i-1]);
        }
        if(n>=2)dp1[n]=dp1[n-1];
        if(n>=2)dp2[2]=nums[1];
        for(int i=3;i<=n;i++){
            dp2[i]=max(nums[i-1]+dp2[i-2], dp2[i-1]);
        }
        return max(dp1[n],dp2[n]);
    }
};
