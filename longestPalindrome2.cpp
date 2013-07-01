/**
 * Longest Palindromic Substring
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 * continuous substring
 */
 
class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        int f[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = 0;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (i == j) {
                    f[j][i] = 1;
                } else {                       
                    if (s[i] == s[j]) {                        
                             if (j + 1 == i) {
                                   f[j][i] = 2;
                                } else if (f[j + 1][i - 1] != 0) {
                                  f[j][i] = 2 + f[j + 1][i - 1];
                                  }
                    }
                    /*
                    if (f[j][i] < f[j + 1][i]) {
                        f[j][i] = f[j + 1][i];
                    }
                    if (f[j][i] < f[j][i - 1]) {
                        f[j][i] = f[j][i - 1];
                    }
                    */
                }                
            }
        }
        
        int max = 0;
        string v;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (max < f[j][i]) {
                    max = f[j][i];
                    v = s.substr(j, i - j + 1);
                }
            }
        }
        
        return v;
        
        
    }
};
