#include <bits/stdc++.h>
class Solution {
    int memo[21][31];

    bool solve(int i, int j, string& s, string& p) {
        // Base Case: If pattern is exhausted, string must also be exhausted
        if (j == p.length()) {
            return i == s.length();
        }

        // Return cached result if we've been in this exact state before
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Check if the current characters match
        bool match = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        // If the NEXT character is a '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Choice 1: Ignore the '*' and the character before it (move j by 2)
            // Choice 2: If current matches, consume 1 string char (move i by 1), keep pattern at '*'
            memo[i][j] = solve(i, j + 2, s, p) || (match && solve(i + 1, j, s, p));
        } 
        // If there is no '*' coming up
        else {
            // If they match, move both forward. If not, this path is dead.
            memo[i][j] = match && solve(i + 1, j + 1, s, p);
        }

        return memo[i][j];
    }

public:
    bool isMatch(string s, string p) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, s, p);
    }
};