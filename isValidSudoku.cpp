/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



A partially filled sudoku which is valid.
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<char> row;
        set<char> column;
        set<char> ss;
        int n = board.size();
        int m = board[0].size();
        if (m != n) return false;
        //check row & column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                //row
                if (board[i][j] != '.' && row.find(board[i][j]) != row.end()) {
                    return false;
                }
                row.insert(board[i][j]);
                //column
                if (board[j][i] != '.' && column.find(board[j][i]) != column.end()) {
                    return false;
                }
                column.insert(board[j][i]);
                int x = (i % 3) * 3 + j % 3;
                int y = (i / 3) * 3 + j / 3;
                if (board[y][x] != '.' && ss.find(board[y][x]) != ss.end()) {
                    return false;
                }
                ss.insert(board[y][x]);
                
            }
            row.clear();
            column.clear();
            ss.clear();
        }
        
        return true;
    }
};