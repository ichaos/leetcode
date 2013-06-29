/**
 * Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
 */

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ss = S.size();
        int ts = T.size();
	    if (ss < ts) return 0;
	    if (ts == 0) return 1;
	    int sum = 0;

	    if (ts == 1) {
		    for (int i = 0; i < ss; i++) {
			    if (S[i] == T[0])
				    sum++;
		    }
		    return sum;
	    }

	    for (int i = 0; i < ss; i++) {
		    if (S[i] == T[0]) {
			    sum += numDistinct(S.substr(i + 1), T.substr(1));
		    }
	    }

	    return sum;
    }
};