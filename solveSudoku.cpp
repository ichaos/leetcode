/**
 * Sudoku Solver
 * Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


 */

class Solution {
private:
    struct pos {
        int i;
        int j;
        pos(int ii, int jj) : i(ii), j(jj) {}
    };
    
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = board.size();
        set<char> row[9];
        set<char> column[9];
        set<char> ss[9];
        
        deque<pos> q;
        int r[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r[i][j] = 0;
                if (board[i][j] != '.') {
                    row[i].insert(board[i][j]);
                    column[j].insert(board[i][j]);
                    ss[(i / 3) * 3 + j / 3].insert(board[i][j]);
                } else {
                    pos p(i, j);
                    q.push_back(p);
                }
            }
        }
        stack<pos> s;

        while (!q.empty()) {
            pos p = q[0];
            q.pop_front();
            //find a possbile value
            char c = ' ';
            bool find = false;
            for (int i = r[p.i][p.j]; i < n; i++) {
                c = '1' + i;
                if (row[p.i].find(c) == row[p.i].end() &&
                column[p.j].find(c) == column[p.j].end() &&
                ss[(p.i / 3) * 3 + p.j / 3].find(c) == ss[(p.i / 3) * 3 + p.j / 3].end()) {
                    board[p.i][p.j] = c;
                    row[p.i].insert(c);
                    column[p.j].insert(c);
                    ss[(p.i / 3) * 3 + p.j / 3].insert(c);
                    find = true;
                    r[p.i][p.j] = i + 1;
                    s.push(p);
                    break;
                }
            }
            if (!find) {
                r[p.i][p.j] = 0;
                q.push_front(p);
                p = s.top();
                q.push_front(p);
                s.pop();
                //clear
                c = board[p.i][p.j];
                row[p.i].erase(c);
                column[p.j].erase(c);
                ss[(p.i / 3) * 3 + p.j / 3].erase(c);
            }
        }
    }
};