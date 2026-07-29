class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        vector<int> ans;
        unordered_map<int,int> counter;
        for(auto num: nums) counter[num]++;

        for(auto p: counter) buckets[p.second].push_back(p.first);

        for(int i=n;i>=0 && ans.size()<k; i--){
            if(!buckets[i].empty()){
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return ans;
    }
};
