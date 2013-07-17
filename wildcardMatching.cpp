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
private:
    struct wildcard {
        const char *s;
        const char *p;
        wildcard(const char *ss, const char *pp) : s(ss), p(pp) {}
    };
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<wildcard> stk;
        
        wildcard wc(s, p);
        stk.push(wc);
        
        while (!stk.empty()) {
            wildcard wc = stk.top();
            stk.pop();
            
            if (wc.s[0] == '\0' && wc.p[0] == '\0') return true;
            
            if (wc.p[0] == '?') {
                if (wc.s[0] != '\0') {
                    wc.s++;
                    wc.p++;
                    stk.push(wc);
                }
            } else if (wc.p[0] == '*') {
                if (wc.s[0] == '\0') {
                    wc.p++;
                    stk.push(wc);
                } else {
                    wildcard t1(wc.s, wc.p + 1);
                    stk.push(t1);
                    t1.s = wc.s + 1;
                    t1.p = wc.p;
                    stk.push(t1);
                    t1.s = wc.s + 1;
                    t1.p = wc.p + 1;
                    stk.push(t1);
                }
            } else if (wc.s[0] == wc.p[0]) {
                wc.s++;
                wc.p++;
                stk.push(wc);
            }
        }
        return false;
    }
};