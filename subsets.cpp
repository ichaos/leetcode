/**
 * Subsets
 * Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 */

class Solution {
private:
    void _subsets(vector<vector<int> > &ret, vector<int> &num, vector<int> &S, int cur) {
        ret.push_back(num);
        for (int i = cur; i < S.size(); i++) {
            //num.insert(, S[i]);
            num.push_back(S[i]);
            _subsets(ret, num, S, i + 1);
            //num.erase(num.begin());
            num.pop_back();
        }
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> num;
        sort(S.begin(), S.end());
        _subsets(ret, num, S, 0);
        return ret;
    }
};