/**
 * Longest Palindromic Substring
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 * This version is not restricted to continuous substring, which is not matched with the requirment of website
 */

#include <iostream>

using namespace std;

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
                                } else {
                                  f[j][i] = 2 + f[j + 1][i - 1];
                                  }
                    }
                    if (f[j][i] < f[j + 1][i]) {
                        f[j][i] = f[j + 1][i];
                    }
                    if (f[j][i] < f[j][i - 1]) {
                        f[j][i] = f[j][i - 1];
                    }
                }                
            }
        }
        
        char v[f[0][n - 1]];
        
        int i = 0, j = n - 1, left = 0, right = f[0][n - 1] - 1;
        
        while (i < j) {
            if (f[i][j] == f[i + 1][j]) {
                i++; continue;
            }
            if (f[i][j] == f[i][j - 1]) {
                j--; continue;
            }
            if (f[i][j] > f[i + 1][j - 1]) {
                v[left++] = s[i];
                v[right--] = s[j];
            }
            i++; j--;
            
        }
        if (i == j) {
              v[left] = s[i];
           }
        cout << f[0][n - 1] << endl;
        for (int i = 0; i < f[0][n - 1]; i++) {
            cout << v[i];
        }
        cout << endl;
        string g(v, f[0][n - 1]);
        return g;
    }
};

int main() {
    string s = "avavad";
    
    Solution sl;
    
    cout << sl.longestPalindrome(s) << endl;
    cin >> s; 
}
