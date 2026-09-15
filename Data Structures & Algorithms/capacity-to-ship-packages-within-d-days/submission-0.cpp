#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Left boundary: Max weight in array
        // Right boundary: Sum of all weights
        int left = 0;
        int right = 0;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        
        int ans = right;
        
        while (left <= right) {
            int capacity = left + (right - left) / 2;
            
            // Simulate the shipping process
            int daysNeeded = 1;
            int currentLoad = 0;
            
            for (int w : weights) {
                if (currentLoad + w > capacity) {
                    daysNeeded++;      // Ship departs, start a new day
                    currentLoad = w;   // Place current package on the new ship
                } else {
                    currentLoad += w;  // Add to current ship
                }
            }
            
            // Adjust binary search boundaries
            if (daysNeeded <= days) {
                ans = capacity;    // This capacity works, save it
                right = capacity - 1; // Try to find a smaller valid capacity
            } else {
                left = capacity + 1;  // Too many days, we need a bigger ship
            }
        }
        
        return ans;
    }
};