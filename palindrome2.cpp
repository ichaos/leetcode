class Solution {
public:
    int minCut(string s) {        
        int n = s.length();
        // isPalin[i][j] means if s[i..j] is a palindrome
        // obviously, we have isPalin[i][i] = true
        bool isPalin[n][n];
        /*
         * storage of optimal value of sub-problem
         * subCut[i] means min cut of substr[0..i]
         * we at least can cut the string into palindrome substring
         * by take as substring every single character and
         * string of length 1 always is a palindrome
         */
        int subCut[n];
        
        for (int i = 0; i < n; i++) {
            subCut[i] = i + 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                isPalin[i][j] = false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {                
                if (s[i] == s[j] && (i - j < 2 || isPalin[j + 1][i - 1]))
                    isPalin[j][i] = true;
                if (isPalin[j][i] && j > 0)
                    subCut[i] = min(subCut[i], subCut[j - 1] + 1);
                else if (isPalin[j][i] && j == 0)
                    subCut[i] = 1;
                    
            }
        }
        return subCut[n - 1] - 1;
    }
};
