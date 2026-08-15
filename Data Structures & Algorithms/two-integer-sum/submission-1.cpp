class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> abc;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(abc.count(complement)){
                return {abc[complement], i};
            }
            abc[nums[i]] = i;
        }
        return {};
    }
};
