class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Loop terminates when left == right
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // We are in the higher left half, minimum is to the right
                left = mid + 1;
            } else {
                // We are in the lower right half, minimum is at mid or to the left
                right = mid;
            }
        }
        
        // When left and right converge, they are pointing directly at the minimum
        return nums[left];
    }
};