class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<1) return 0;
        unordered_set<int> s;
        for(int i: nums) s.insert(i);

        int l=1;
        for(auto i:s){
            if(s.find(i-1) == s.end()){
                int c=1;
                int x=i;
                while(s.find(x+1)!=s.end()){
                    c+=1;
                    x+=1;
                }
                l=max(l,c);
            }
        }
        return l;
    }
};
