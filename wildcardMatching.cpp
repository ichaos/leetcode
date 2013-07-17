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
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s[0] == '\0' && p[0] == '\0') return true;
        
        if (p[0] == '?') {
            if (s[0] == '\0') return false;
            return isMatch(s + 1, p + 1);
        }
        if (p[0] == '*') {
            if (s[0] == '\0') {
                if (isMatch(s, p + 1)) return true;
                return false;
            } else {
                if (isMatch(s, p + 1) || isMatch(s + 1, p + 1) ||
                    isMatch(s + 1, p))
                    return true;
                else 
                    return false;
            }
        }
        if (s[0] == p[0]) return isMatch(s + 1, p + 1);
        return false;
    }
};