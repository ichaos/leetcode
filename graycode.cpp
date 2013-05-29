class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> appear;
        vector<int> res;
        int cur = 0;
        appear.insert(cur);
        res.push_back(cur);
        bool cont = false;
        int tmp = 0;
        do {
            cont = false;
            for (int i = 0; i < n; i++) {
                tmp = cur ^ (0x1 << i);
                if (appear.find(tmp) == appear.end()) {
                    cont = true;
                    cur = tmp;
                    res.push_back(cur);
                    appear.insert(tmp);
                    break;
                }
            }
        } while (cont);
        return res;
    }
};