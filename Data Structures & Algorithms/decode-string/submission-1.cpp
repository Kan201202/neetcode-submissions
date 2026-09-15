class Solution {
public:
    string decodeString(string s) {
        int i = 0; // Reference pointer to track progress across recursive calls
        return decode(s, i);
    }
    
private:
    string decode(const string& s, int& i) {
        string res = "";
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i])) {
                // If it's a letter, just add it to the current string
                res += s[i];
                i++;
            } 
            else {
                // If it's a number, calculate the full multiplier
                int k = 0;
                while (i < s.length() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                
                i++; // Skip the '['
                
                // Recursively decode the inner string
                string decodedString = decode(s, i);
                
                i++; // Skip the ']'
                
                // Multiply and append the decoded string
                while (k > 0) {
                    res += decodedString;
                    k--;
                }
            }
        }
        
        return res;
    }
};