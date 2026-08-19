#include <string>

class Solution {
private:
    // Helper function to check if a specific substring is a perfect palindrome
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // When a mismatch is found, use your two options!
            if (s[left] != s[right]) {
                // Option 1: Skip the left character (left + 1)
                // Option 2: Skip the right character (right - 1)
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            
            // If they match, keep moving inwards
            left++;
            right--;
        }
        
        // If we made it through the whole string without mismatches, it's already a palindrome
        return true; 
    }
};