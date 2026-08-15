class Solution {
public:
    string strsort(string s){
        int count[26] = {0};
        for(char c:s){
            count[c-'a']++;
        }

        string t;
        for(int i=0;i<26;i++){
            t+= string(count[i], i+'a');
        }
        return t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            mp[strsort(s)].push_back(s);
        }

        vector<vector<string>> anagrams;
        for(auto p:mp){
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
