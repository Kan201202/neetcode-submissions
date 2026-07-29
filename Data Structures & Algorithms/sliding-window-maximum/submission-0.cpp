class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n), result(n - k + 1);

        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        // Fill left max for blocks
        for (int i = 1; i < n; ++i) {
            if (i % k == 0)
                left[i] = nums[i];  // new block
            else
                left[i] = max(left[i - 1], nums[i]);
        }

        // Fill right max for blocks
        for (int i = n - 2; i >= 0; --i) {
            if ((i + 1) % k == 0)
                right[i] = nums[i];  // new block
            else
                right[i] = max(right[i + 1], nums[i]);
        }

        // Build result
        for (int i = 0; i <= n - k; ++i) {
            result[i] = max(right[i], left[i + k - 1]);
        }

        return result;
    }
};
