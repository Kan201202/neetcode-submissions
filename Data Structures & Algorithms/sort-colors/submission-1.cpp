class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Found a 0, move it to the front
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) {
                // Found a 1, leave it in the middle
                mid++;
            } 
            else { // nums[mid] == 2
                // Found a 2, move it to the back
                swap(nums[mid], nums[high]);
                high--;
                // Note: We don't increment mid here because the new element 
                // swapped to the mid position still needs to be checked.
            }
        }
    }
};