class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> abc;
        for(int i=0; i<n;i++){
            if(abc[nums[i]] >=1) return 1;
            else abc[nums[i]]++;
        }
        return 0;
    }
};