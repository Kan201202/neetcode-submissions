class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                if(s[i]>='A' && s[i]<='Z'){
                    s[i] = s[i] + 32;
                }
                t+=s[i];
            }
        }

        int i=0;
        int j=t.size()-1;
        while(i<=j){
            if(t[i] != t[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
