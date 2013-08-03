/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 */
class Solution {
private:
    bool isLegal(string s, int i) {
        if (s[i] == '1') return (s[i + 1] >= '0' && s[i + 1] <= '9');
        if (s[i] == '2') return (s[i + 1] >= '0' && s[i + 1] < '7');
        return false;
    }
    
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        
        if (n < 1) return 0;
        vector<int> ret(n + 1, 0);
        ret[0] = 1;
        
        for (int i = 0; i < n; i++) {
            if (s[i] <= '9' && s[i] >= '1') ret[i + 1] += ret[i];
            if (isLegal(s, i)) ret[i + 2] += ret[i];
        }
        
        return ret[n];
    }
};