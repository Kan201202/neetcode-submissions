#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            
            if (window.find(nums[i]) != window.end()) {
                return true;
            }
            
            window.insert(nums[i]);
        }
        
        return false;
    }
};