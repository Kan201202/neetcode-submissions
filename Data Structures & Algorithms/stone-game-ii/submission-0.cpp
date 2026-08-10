#include<bits/stdc++.h>
class Solution {
public:

    int dp[101][201];
    int suffixsum[101];

    int solve(int i, int M, int n, vector<int>& piles){
        if(i>=n)return 0;
        if(dp[i][M] != -1) return dp[i][M];

        if(i + (2*M) >= n){
            return suffixsum[i];
        }

        int maxi = 0;
        for(int x=1;x<=(2*M);x++){
            int oppo = solve(i+x, max(M,x), n, piles);
            int myscor = suffixsum[i] - oppo;
            maxi = max(maxi, myscor);
        }

        return dp[i][M] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));

        suffixsum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffixsum[i] = suffixsum[i+1] + piles[i];
        }

        return solve(0, 1, n, piles);
    }
};