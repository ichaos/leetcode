/**
 * Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
    int numDistinct(string S, string T) {
        int ss = S.size();
        int ts = T.size();
        
        if (ss == 0 || ts == 0) return 0;
        
        int f[ts + 1][ss + 1];
        for (int i = 0; i <= ts; i++) {
            for (int j = 0; j <= ss; j++) {
                f[i][j] = 0;
            }
        }
        for (int j = 0; j <= ss; j++) {
            f[0][j] = 1;
        }
        
        for (int i = 1; i <= ts; i++) {
            for (int j = 1; j <= ss; j++) {
                if (T[i - 1] == S[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
                } else
                    f[i][j] = f[i][j - 1];
            }
        }
        return f[ts][ss];
    }
};

int main() {
	string s = "aaaa";
	string t = "aa";

	Solution sl;

	cout << "1. " << sl.numDistinct(s, t) << endl;
}