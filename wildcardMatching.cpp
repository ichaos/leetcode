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
        if (!s && !p) return true;
        
        int sl = 0;
        const char *ss = s;
        while (ss[0] != '\0') {
            sl++;
            ss++;
        }
        int pl = 0;
        const char *pp = p;
        while (pp[0] != '\0') {
            pp++;
            pl++;
        }
        
        if (s[0] == '\0') {
            pp = p;
            while (pp[0] == '*') {
                pp++;
            }
            if (pp[0] != '\0') return false;
            return true;
        }
        
        ss = s;
        pp = p;
        
        bool match[sl + 1][pl + 1];
        for (int i = 0; i < sl + 1; i++) {
            for (int j = 0; j < pl + 1; j++) {
                match[i][j] = false;
            }
        }
        match[0][0] = true;
        
        //pp = p;
        int i = 0;
        while (p[i] == '*') {
            for (int j = 0; j < sl + 1; j++) {
                match[j][i + 1] = true;
            }        
            i++;
        }
        
        for (int i = 1; i <= sl; i++) {
            for (int j = 1; j <= pl; j++) {
                if (s[i - 1] == p[j - 1] && match[i - 1][j - 1]) {
                    match[i][j] = true;
                } else if (p[j - 1] == '?') {
                    match[i][j] = match[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (match[i - 1][j - 1] || match[i][j - 1] || match[i - 1][j])
                        match[i][j] = true;
                } else
                    match[i][j] = false;                
            }
        }
        return match[sl][pl];
    }
};