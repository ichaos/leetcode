/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

class Solution {
private:
    int min(int a, int b) {
        return (a < b) ? a : b;
    }

public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() < 1) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        
        int level = triangle.size();
        
        int lll = triangle[level - 1].size();
        int minp[lll];
        for (int i = 0; i < lll; i++)
            minp[i] = triangle[level - 1][i];
        
        for (int i = level; i > 1; i--) {
            for (int j = 0; j < triangle[i - 2].size(); j++) {
                minp[j] = triangle[i - 2][j] + min(minp[j], minp[j + 1]);
            }
        }
        //return pathSum(triangle, 1, 1);
        return minp[0];
    }
};