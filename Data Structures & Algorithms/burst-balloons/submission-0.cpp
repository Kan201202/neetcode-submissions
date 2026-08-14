#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dp[302][302];

    int solve(int left, int right, vector<int>& nums) {
        // Base Case: If the range is invalid, there are no balloons to pop
        if (left > right) {
            return 0;
        }
        
        // Return cached result if already calculated
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int max_coins = 0;

        // Try making every balloon in the current range the LAST one to burst
        for (int i = left; i <= right; i++) {
            
            // 1. The coins from bursting 'i' LAST
            int coins = nums[left - 1] * nums[i] * nums[right + 1];
            
            // 2. The coins from completely clearing the left side of 'i'
            int left_subproblem = solve(left, i - 1, nums);
            
            // 3. The coins from completely clearing the right side of 'i'
            int right_subproblem = solve(i + 1, right, nums);
            
            // Add them all together for the total score of this timeline
            int total_score = coins + left_subproblem + right_subproblem;
            
            // Keep the maximum possible score
            max_coins = max(max_coins, total_score);
        }

        // Write it down before returning
        return dp[left][right] = max_coins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Create the new array with the unbreakable '1' boundaries
        vector<int> padded_nums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            padded_nums[i + 1] = nums[i];
        }

        memset(dp, -1, sizeof(dp));

        // Start the game by passing only the movable balloons (index 1 to n)
        return solve(1, n, padded_nums);
    }
};