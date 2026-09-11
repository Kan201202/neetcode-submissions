class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
            char c = t[i];
            mp[c]++;
        }

        int need = mp.size();
        int have = 0;
        unordered_map<char,int> mp1;
        int left=0, right=0;


        string khooshi = "";
        int min_len = INT_MAX;
        int start = -1;
        while(right<s.size()){
            char c = s[right];
            if(mp.count(c)>0){
                mp1[c]++;
                if(mp1[c]==mp[c])have++;

            }
            right++;
            
            while(have==need){
                if((right-left)<min_len){
                    start = left;
                    min_len = right - left;
                }

                char k = s[left];
                if(mp1.count(k)>0){
                    mp1[k]--;
                    if(mp1[k]<mp[k])have--;
                }
                left++;
                
            }
        }

        if(start==-1)return khooshi;
        khooshi = s.substr(start, min_len);
        return khooshi;
    }
};
