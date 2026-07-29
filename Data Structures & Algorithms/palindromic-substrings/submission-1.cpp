class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        if(n<=1) return n;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            ans++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans++;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]!=0){
                    dp[i][j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
