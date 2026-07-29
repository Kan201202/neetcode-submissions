class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2) return min(cost[0], cost[1]);
        if(n==3) return min((cost[0]+cost[2]), cost[1]);

        vector<int> dp0(n,0);
        vector<int> dp1(n,0);
        
        dp0[0] = cost[0];
        dp0[1] = cost[0] + cost[1];
        for(int i=2;i<n;i++){
            dp0[i] = cost[i] + min(dp0[i-1], dp0[i-2]);
        }

        dp1[1] = cost[1];
        dp1[2] = cost[1] + cost[2];

        for(int i=3;i<n;i++){
            dp1[i] = cost[i] + min(dp1[i-1], dp1[i-2]);
        } 

        return min({dp0[n-1], dp1[n-1], dp0[n-2], dp1[n-2]});
    }
};
