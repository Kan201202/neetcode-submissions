class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        int curr = 0;

        for(int num: nums){
            curr += num;
            int target = curr - k;
            if(mp.find(target) != mp.end())count+=mp[target];

            mp[curr]++;

        }
        return count;
    }
};