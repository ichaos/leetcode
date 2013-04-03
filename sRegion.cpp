class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> access;
        for (int i = 0; i < board.size(); i++) {
            vector<int> tmp;
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X') {
                    tmp.push_back(1);                    
                } else {
                    tmp.push_back(0);
                }                
            }
            access.push_back(tmp);
        }
        
        for (int i = 0; i < access.size(); i++) {
            for (int j = 0; j < access[i].size(); j++) {
                if (access[i][j] == 1)
                    continue;
                else {
                    bool surrounded = true;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    access[i][j] = 1;
                    vector<pair<int, int>> r;
                    r.push_back(make_pair(i, j));
                    while (!q.empty()) {
                        int ci = q.front().first;
                        int cj = q.front().second;
                        q.pop();
                        if (ci == 0 || ci == access.size() - 1 || cj == 0 || cj == access[i].size() - 1)
                            surrounded = false;   
                        if (ci > 0 && access[ci - 1][cj] == 0) {
                            q.push(make_pair(ci - 1, cj));
                            r.push_back(make_pair(ci - 1, cj));
                            access[ci - 1][cj] = 1;
                        }
                        if (ci + 1 < access.size() && access[ci + 1][cj] == 0) {
                            q.push(make_pair(ci + 1, cj));
                            access[ci + 1][cj] = 1;
                            r.push_back(make_pair(ci + 1, cj));
                        }
                        if (cj > 0 && access[ci][cj - 1] == 0) {
                            q.push(make_pair(ci, cj - 1));
                            access[ci][cj - 1] = 1;
                            r.push_back(make_pair(ci, cj - 1));
                        }
                        if (cj < access[i].size() - 1 && access[ci][cj + 1] == 0) {
                            q.push(make_pair(ci, cj + 1));
                            access[ci][cj + 1] = 1;
                            r.push_back(make_pair(ci, cj + 1));
                        }
                    }
                    if (surrounded) {
                        for (int k = 0; k < r.size(); k++) {
                            board[r[k].first][r[k].second] = 'X';
                        }
                    }
                }
            }
        }
        
        //print
        /*
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }*/
    }
};