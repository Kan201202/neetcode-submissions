class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> abc(2*n);
        for(int i=0;i<n;i++)abc[i] = nums[i];
        for(int i=0;i<n;i++)abc[i+n] = nums[i];
        return abc;
    }
};