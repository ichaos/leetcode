/**
 * Unique Paths II
 * Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int ss[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                ss[i][j] = 0;
            }
        }
        ss[1][1] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1]) {
                    ss[i][j] = 0;
                } else {
                    if (i == 1 && j == 1)
                        ss[i][j] = 1;
                    else
                        ss[i][j] = ss[i - 1][j] + ss[i][j - 1];
                }
            }
        }
        return ss[m][n];
    }
};