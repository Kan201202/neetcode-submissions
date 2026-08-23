class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int n=s.length();
        vector<int>abc(26,0);
        int maxcount=0, ans=0;
        for(int right=0; right<n; right++){
            abc[s[right]-'A']++;
            maxcount=max(maxcount,abc[s[right]-'A']);

            while((right-left+1) - maxcount> k){
                abc[s[left] - 'A']--;
                left++;
            }

            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
