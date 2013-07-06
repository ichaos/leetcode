/**
 * Regular Expression Matching
 * Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        bool res;
        if (*s == '\0') {
            while (*p != '\0') {
                if (*(p + 1) == '*') {
                    p += 2; continue;
                }
                if (*p == '*') {
                    p++; continue;
                }
                return false;
            }
            return true;
        }
            
            if (*p == '\0') return false;
            
            if (*(p + 1) == '*') {
                res = isMatch(s, p + 2);
                if (res) return true;
                if (*p == '.' || *p == *s) {
                    if (isMatch(s + 1, p)) {
                        return true;
                    }
                }
                return false;
            }
            
            if (*p == *s || *p == '.') return isMatch(s + 1, p + 1);
            
        return false;
    }
};