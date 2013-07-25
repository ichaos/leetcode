/**
 * Word Search
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */
class Solution {
private:
    bool _exist(vector<vector<char> > &board, vector<vector<bool> > &map, string word, int cur, int x, int y) {
        if (cur == word.size()) return true;
        
        //up
        if (x > 0) {
            if (map[x - 1][y] == false && board[x - 1][y] == word[cur]) {
                map[x - 1][y] = true;
                if (_exist(board, map, word, cur + 1, x - 1, y)) return true;
                map[x - 1][y] = false;
            }
        }
        //down
        if (x < board.size() - 1) {
            if (map[x + 1][y] == false && board[x + 1][y] == word[cur]) {
                map[x + 1][y] = true;
                if (_exist(board, map, word, cur + 1, x + 1, y)) return true;
                map[x + 1][y] = false;
            }
        }
        //left
        if (y > 0) {
            if (map[x][y - 1] == false && board[x][y - 1] == word[cur]) {
                map[x][y - 1] = true;
                if (_exist(board, map, word, cur + 1, x, y - 1)) return true;
                map[x][y - 1] = false;
            }
        }
        //right
        if (y < board[0].size() - 1) {
            if (map[x][y + 1] == false && board[x][y + 1] == word[cur]) {
                map[x][y + 1] = true;
                if (_exist(board, map, word, cur + 1, x, y + 1)) return true;
                map[x][y + 1] = false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<bool> > map(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    map[i][j] = true;
                    if (_exist(board, map, word, 1, i, j)) return true;
                    map[i][j] = false;
                }
            }
        }
        return false;
    }
};