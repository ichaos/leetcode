/**
 * Search a 2D Matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0; 
        int j = m * n - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            int x = mid / n;
            int y = mid % n;
            if (target == matrix[x][y]) return true;
            
            if (target < matrix[x][y]) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
};