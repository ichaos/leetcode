/**
 * Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
 */
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // dynamic programming
        if (!*s && !*p) return true;
        
        // length of s
        int sl = 0;
        const char *ss = s;
        while (!*ss) {
            sl++;
            ss++;
        }
        int pl = 0;
        const char *pp = p;
        while (!*pp) {
            pl++;
            pp++;
        }
        cout << "string length is " << sl << ", pattern length is " << pl << endl;
        vector<vector<bool> > dp(pl + 1, vector<bool>(sl + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= pl; i++) {
            if (p[i - 1] == '*') dp[i][0] = dp[i - 1][0];
            else dp[i][0] = false;
        }
        
        for (int i = 1; i <= sl; i++) {
            dp[0][i] = false;
        }
        
        for (int i = 1; i <= pl; i++) {
            for (int j = 1; j <= sl; j++) {
                if (s[j - 1] == p[i - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    dp[i][j] = false;
                    for (int k = 0; k <= j; k++) {
                        if (dp[i - 1][k]) {
                            dp[i][j] = true; break;
                        }
                    }
                    if (dp[i][j]) {
                        for (j++; j <= sl; j++) {
                            dp[i][j] = true;
                        }
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[pl][sl];
    }
};

int main () {
    Solution s;
    cout << s.isMatch("abbbbbaabbababaabaabbbbababbbabbbaaaaaabaaaaaaabaabbaaabababbbaabaabbabbabbaabaaabaababbbbbaababaabbaaaabbbbabaaaaababababbabbabbbabbababaabbaabaaaaabbaaabbbbaaaabbaabbbbbabbabbabbbaaaabbbaabaaabbbaaaa", "ba**a*a*a****a***ba**aa*b***a*ab**a**a***a**bbb***bb*baab**ba***b*ba****abbb**abab******abaa***abaaa***") << endl;
}