/**
 * Permutations II
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
 */
class Solution {
private:
    void _permute(vector<int> cur, vector<int> remain, vector<vector<int> > &ret) {
        if (remain.size() == 0) ret.push_back(cur);
        int l = 0;
        int ps = cur.size();
        for (int i = 0; i < remain.size();) {
            if (ps && cur[ps - 1] == remain[i]) {
                i++;
                continue;
            }
            l = 0;
            vector<int> next(cur);
            vector<int> tmp(remain);
            while (i + l < remain.size() && remain[i] == remain[i + l]) {
                l++;
                next.push_back(tmp[i]);
                tmp.erase(tmp.begin() + i);
                _permute(next, tmp, ret);
            }  
            i += l;
            //_permute(next, tmp, ret);
        }
    }
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        vector<vector<int> > ret;
        vector<int> cur;
        
        _permute(cur, num, ret);
        return ret;
    }
};