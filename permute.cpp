/**
 * Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
class Solution {
private:
    void _permute(vector<int> cur, vector<int> remain, vector<vector<int> > &ret) {
        if (remain.size() == 0) ret.push_back(cur);
        
        for (int i = 0; i < remain.size(); i++) {
            cur.push_back(remain[i]);
            vector<int> tmp(remain);
            tmp.erase(tmp.begin() + i);
            _permute(cur, tmp, ret);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        vector<vector<int> > ret;
        vector<int> cur;
        
        _permute(cur, num, ret);
        return ret;
    }
};