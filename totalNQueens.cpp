/**
 * N-Queens II
 * Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
private:
    void _totalNQueens(int row, int ld, int rd, int upper, int &cnt) {
        if (row != upper) {
            int pos = upper & (~(row | ld | rd));
            
            while (pos != 0) {
                int p = pos & (-pos);
                pos = pos - p;
                _totalNQueens(row + p, (ld + p) >> 1, (rd + p) << 1, upper, cnt);
            }
        } else cnt++;
    }
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //REMEMBER: n < 32
        int upper = (1 << n) - 1;
        int total = 0;
        _totalNQueens(0, 0, 0, upper, total);
        return total;
    }
};