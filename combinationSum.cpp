#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _combinationSum(vector<int> v, int target, vector<int> &candidates,
        vector<vector<int> > &ret) {
        if (target == 0) {
            ret.push_back(v);
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (v.size() > 0 && v[v.size() - 1] > candidates[i]) continue;
            if (candidates[i] <= target) {                
                vector<int> tmp(v);
                tmp.push_back(candidates[i]);
                _combinationSum(tmp, target - candidates[i], candidates, ret);
            }            
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        
        vector<int> tmp;
        
        _combinationSum(tmp, target, candidates, ret);
        vector<int> *prev = &ret[0];
        for (int i = 1; i < ret.size(); i++) {
            //check
            if (prev->size() != ret[i].size()) {
                prev = &ret[i];
                continue;
            } else {
                bool dup = true;
                for (int j = 0; j < ret[i].size(); j++) {
                    if ((*prev)[j] != ret[i][j]) {
                        prev = &ret[i];
                        dup = false;
                        break;
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

int main() {
    Solution s;
    vector<int> can;
    can.push_back(1);
    can.push_back(2);
    std::vector<std::vector<int> > v = s.combinationSum(can, 4);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    //remove duplicated vector
    //vector<int> prev = 
}