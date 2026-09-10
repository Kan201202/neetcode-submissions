class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(int i=0;i<s1.size();i++){
            int temp = s1[i]-'a';
            freq[temp]++;
        }

        vector<int> freq2(26,0);
        if(s1.size()>s2.size())return false;
        for(int i=0;i<s1.size();i++){
            int temp = s2[i]-'a';
            freq2[temp]++;
        }
        if(freq==freq2)return true;
        for(int i=s1.size();i<s2.size();i++){
            int temp = s2[i] - 'a';
            int temp2 = s2[i-s1.size()] - 'a';
            freq2[temp2]--;
            freq2[temp]++;
            if(freq2==freq)return true;
        }

        return false;
    }
};
