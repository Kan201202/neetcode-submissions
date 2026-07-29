class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int win=s1.length();
        if(win> s2.length()) return false;

        vector<int> abc1(26,0);
        vector<int> abc2(26,0);

        for(int i=0;i<win;i++){
            abc1[s1[i]-'a'] ++;
        }

        for(int i=0;i<win;i++){
            abc2[s2[i]-'a'] ++;
        }

        int left=0;
        int right=win-1;

        while(right<s2.length()){
            if(abc1 == abc2) return true;
            else{
                abc2[s2[left]-'a']--;
                left++;
                right++;
                if(right== s2.length()) break;
                else abc2[s2[right]-'a']++;
            }
        }
        return false;
    }
};
