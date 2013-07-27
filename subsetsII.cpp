/**
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */
class Solution {
private:
    void _subsetsWithDup(vector<vector<int> > &ret, vector<int> &S, vector<int> &num, int i,
        vector<bool> &map) {
        ret.push_back(num);
        
        for ( ; i < S.size(); i++) {
            if (map[i]) continue;
            map[i] = true;
            num.push_back(S[i]);
            _subsetsWithDup(ret, S, num, i + 1, map);
            num.pop_back();
            map[i] = false;
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> num;
        vector<bool> map(S.size(), false);
        sort(S.begin(), S.end());
        _subsetsWithDup(ret, S, num, 0, map);
        
        //deduplicate
        sort(ret.begin(), ret.end());
        vector<int> *prev = &ret[0];
        for (int i = 1; i < ret.size(); i++) {
            if (ret[i].size() != prev->size()) {
                prev = &ret[i];
            } else {
                bool dup = true;
                for (int j = 0; j < ret[i].size(); j++) {
                    if ((*prev)[j] != ret[i][j]) {
                        prev = &ret[i];
                        dup = false;
                    }
                }
                if (dup) {
                    ret.erase(ret.begin() + i);
                    i--;
                }
            }
        }
        return ret;
    }
};