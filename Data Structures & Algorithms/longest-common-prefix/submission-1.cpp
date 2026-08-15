#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Sort the array of strings lexicographically
        sort(strs.begin(), strs.end());
        
        // Only compare the first and last strings
        string first = strs.front();
        string last = strs.back();
        int i = 0;
        
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        
        return first.substr(0, i);
    }
};