class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp array represents the previous row
        vector<int> dp(n + 1, 0);
        
        // Base case: 0th row (Comparing empty word1 to word2)
        // If word1 is empty, we must insert 'j' characters to match word2
        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }
        
        // Process each character in word1
        for (int i = 1; i <= m; i++) {
            
            // prev holds the Top-Left diagonal value. 
            // At the start of a new row, the Top-Left for j=1 is the old dp[0]
            int prev = dp[0]; 
            
            // Update the Left Wall (Comparing word1 to an empty word2)
            // If word2 is empty, we must delete 'i' characters
            dp[0] = i;
            
            // Loop FORWARDS
            for (int j = 1; j <= n; j++) {
                
                // Save the current cell before we overwrite it! 
                // This will become the Top-Left diagonal for the NEXT iteration.
                int temp = dp[j];
                
                if (word1[i - 1] == word2[j - 1]) {
                    // Match: Just take the Top-Left diagonal (no cost)
                    dp[j] = prev;
                } else {
                    // Mismatch: 1 + min(Up, Left, Top-Left)
                    // Up = dp[j], Left = dp[j-1], Top-Left = prev
                    dp[j] = 1 + min({dp[j], dp[j - 1], prev});
                }
                
                // Put the saved value into prev for the next loop
                prev = temp;
            }
        }
        
        return dp[n];
    }
};