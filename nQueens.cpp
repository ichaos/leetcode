/**
 * N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n�n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _solveNQueens(int q, vector<int> &cur, vector<vector<int> > &ret, int n) {
        if (cur.size() == n) {
            ret.push_back(cur);
            return;
        }
        
        bool find = true;
        for (int i = 0; i < n; i++) { //the ith queue on the ith row
            find = true;
            for (int j = 0; j < cur.size(); j++) { //check if i is a possible position for qth queue
                if (i == cur[j] || q - j == i - cur[j] || j - q == i - cur[j]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                cur.push_back(i);
                _solveNQueens(q + 1, cur, ret, n);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;
        vector<int> cur;
        _solveNQueens(0, cur, v, n);
        
        vector<vector<string> > ret;
        
        for (int i = 0; i < v.size(); i++) {
            vector<string> s;
            for (int j = 0; j < v[i].size(); j++) {
                string tmp(n, '.');
                tmp[v[i][j]] = 'Q';
                s.push_back(tmp);
            }
            ret.push_back(s);
        }
        return ret;
    }
};

int main () {
    Solution s;
    vector<vector<string> > ret = s.solveNQueens(4);

    for (int i = 0; i < ret.size(); i++) {
        cout << "Solution " << i + 1 << ": " << endl;
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << endl;
        }
        cout << endl;
    }
}