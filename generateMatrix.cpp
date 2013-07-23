/**
 * generateMatrix
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > m(n, vector<int>(n, 0));
        if (n < 1) return m;
        enum direction { RIGHT = 0, DOWN, LEFT, UP };
        int v = 1;
        int x = 0;
        int y = 0;
        int d = RIGHT;
        bool wall[n][n];
        for (int i = 0; i < n; i++) {
            //vector<int> tmp(n, 0);
            //m.push_back(tmp);
            for (int j = 0; j < n; j++) {
                wall[i][j] = false;
            }
        }
        
        m[x][y] = v++;
        if (v == n * n + 1) return m;
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
                if (x + 1 < n && !wall[x + 1][y]) {
                    x++;
                } else
                    change = true;
                break;
                default: break;
            }
            if (change) {
                d = (d + 1) % 4;                
            } else {
                m[x][y] = v++;
                if (v == n * n + 1) return m;
                wall[x][y] = true;
            }
        }
        return m;
    }
};