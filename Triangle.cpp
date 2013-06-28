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
    int pathSum(vector<vector<int> > &triangle, int level, int i) {
        if (level == triangle.size()) return triangle[level - 1][i - 1];
        int left = pathSum(triangle, level + 1, i);
        int right = pathSum(triangle, level + 1, i + 1);
        if (left > right) left = right;
        
        return left + triangle[level - 1][i - 1];
    }

public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() < 1) return 0;
        
        return pathSum(triangle, 1, 1);
    }
};