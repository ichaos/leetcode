/**
 * uniquePaths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // A(m, m + n) / A(m)
        if (m > n) {
            //swap m, m
            int tmp = m;
            m = n;
            n = tmp;
        }
        m--;
        n--;
        vector<int> am;
        for (int i = 2; i <= m; i++) {
            am.push_back(i);
        }
        
        long long amn = 1;
        if (m != 0)
            for (int i = n + 1; i <= m + n; i++) {
                amn *= i;
                for (int j = 0; j < am.size(); j++) {
                    if (!(amn % am[j])) {
                        amn /= am[j];
                        am.erase(am.begin() + j);
                        j--;
                    }
                }
            }
        
        return amn;
    }
};