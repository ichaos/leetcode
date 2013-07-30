/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */
class Solution {
private:
    bool _isInterleave(string &s1, int i1, string &s2, int i2, string &s3, int i3) {
        if (i3 == s3.size()) return true;
        
        if (s1.size() > i1 && s1[i1] == s3[i3])
            if (_isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1))
                return true;
            
        if (s2.size() > i2 && s2[i2] == s3[i3])
            if (_isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1))
                return true;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        if (s1.size() + s2.size() != s3.size()) return false;
        return _isInterleave(s1, 0, s2, 0, s3, 0);
    }
};