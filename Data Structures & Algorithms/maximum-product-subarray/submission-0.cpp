class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double ans = nums[0];
        double leftProduct = 1;
        double rightProduct = 1;

        for (int i = 0; i < n; i++) {
            leftProduct = (leftProduct == 0 ? 1 : leftProduct) * nums[i];
            rightProduct = (rightProduct == 0 ? 1 : rightProduct) * nums[n - 1 - i];
            ans = max({ans, leftProduct, rightProduct});
        }

        return ans;
    }
};