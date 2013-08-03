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
    void _subsetsWithDup(vector<vector<int> > &ret, vector<int> &S, vector<int> &num, int i) {
        ret.push_back(num);
        
        for (int j = i ; j < S.size(); j++) {
            if (i != j && S[j] == S[j - 1]) continue;

            num.push_back(S[j]);
            _subsetsWithDup(ret, S, num, j + 1);
            num.pop_back();
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> num;
        sort(S.begin(), S.end());
        _subsetsWithDup(ret, S, num, 0);
        return ret;
    }
};