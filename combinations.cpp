/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

 */
class Solution {
private:
    void _combine(vector<vector<int> > &ret, vector<bool> &r, vector<int> &num, int cur, int k, int n) {
        if (num.size() == k) {
            ret.push_back(num);
            return;
        }
        for (int i = cur; i < n; i++) {
            if (r[i]) continue;
            r[i] = true;
            num.push_back(i + 1);
            _combine(ret, r, num, i + 1, k, n);
            num.pop_back();
            r[i] = false;
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<bool> r(n, false);
        vector<int> num;
        _combine(ret, r, num, 0, k, n);
        return ret;
    }
};