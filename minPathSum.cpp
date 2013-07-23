/*
 * Minimum Path Sum
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        
        int ss[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                ss[i][j] = 0;
            }
        }
        
        for (int i = 2; i <= m; i++) {
            ss[i][0] = INT_MAX;
        }
        for (int j = 2; j <= n; j++) {
            ss[0][j] = INT_MAX;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (ss[i - 1][j] < ss[i][j - 1]) {
                    ss[i][j] = ss[i - 1][j] + grid[i - 1][j - 1];
                } else {
                    ss[i][j] = ss[i][j - 1] + grid[i - 1][j - 1];
                }
            }
        }
        
        return ss[m][n];
    }
};