/**
 * Edit Distance
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
 */
class Solution {
private:
    int lcs(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int table[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            table[i][0] = 0;
        }
        for (int i = 0; i < n + 1; i++) {
            table[0][i] = 0;
        }
        
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1])
                    table[i][j] = table[i - 1][j - 1] + 1;
                else {
                    table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }
        return table[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = word1.size();
        int n = word2.size();
        
        int table[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) table[i][0] = i;
        for (int i = 0; i < n + 1; i++) table[0][i] = i;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    table[i + 1][j + 1] = table[i][j];
                } else {
                    table[i + 1][j + 1] = std::min(table[i][j] + 1,
                        std::min(table[i + 1][j] + 1, table[i][j + 1] + 1));
                }
            }
        }
        return table[m][n];
    }
};