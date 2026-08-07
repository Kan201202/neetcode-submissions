class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: Subarrays of length 1
        // If there's only 1 stone left, you take it. Your opponent gets 0.
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        // Build up from subarrays of length 2 to length N
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Calculate the right endpoint
                
                int pickLeft = nums[i] - dp[i + 1][j];
                int pickRight = nums[j] - dp[i][j - 1];
                
                dp[i][j] = max(pickLeft, pickRight);
            }
        }
        
        // If the Net Advantage for the full array is >= 0, Player 1 wins
        return dp[0][n - 1] >= 0;
    }
};