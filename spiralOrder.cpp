/**
 * spiralOrder
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
 */
class Solution {
private:
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        enum direction { RIGHT = 0, DOWN, LEFT, UP };
        int m = matrix.size();
        if (m < 1) return v;
        int n = matrix[0].size();
        int x = 0;
        int y = 0;
        int d = RIGHT;
        bool wall[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                wall[i][j] = false;
            }
        }
        
        v.push_back(matrix[x][y]);
        wall[x][y] = true;
        bool change = false;
        //int end = 0;
        while (1) {
            //next step
            change = false;
            switch (d) {
                case LEFT:
                if (y - 1 >= 0 && !wall[x][y - 1]) {
                    y--;
                } else {
                    change = true;
                }
                break;
                case RIGHT:
                if (y + 1 < n && !wall[x][y + 1]) {
                    y++;
                } else {
                    change = true;
                }
                break;
                case UP:
                if (x - 1 >= 0 && !wall[x - 1][y]) {
                    x--;
                } else
                    change = true;
                break;
                case DOWN:
                if (x + 1 < m && !wall[x + 1][y]) {
                    x++;
                } else
                    change = true;
                break;
                default: break;
            }
            if (change) {
                //check next
                if (v.size() == m * n) return v;
                d = (d + 1) % 4;                
            } else {
                v.push_back(matrix[x][y]);
                wall[x][y] = true;
            }
        }
        return v;
    }
};