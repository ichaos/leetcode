/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 * [
 *      [1],
 *      [1,1],
 *      [1,2,1],
 *      [1,3,3,1],
 *      [1,4,6,4,1],
 *      ......
 * ]
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (numRows < 1) return res;
        int a1[] = {1};
        vector<int> v1(a1, a1 + 1);
        res.push_back(v1);
        if (numRows == 1) return res;
        int a2[] = {1,1};
        vector<int> v2(a2, a2 + 2);
        vector<int> prev = v2;
        res.push_back(v2);
        
        for (int i = 2; i < numRows; i++) {
            v2.clear();
            v2.push_back(1);
            for (int j = 1; j < i; j++) {
                v2.push_back(prev[j - 1] + prev[j]);
            }
            v2.push_back(1);
            res.push_back(v2);
            prev = v2;
        }
        return res;
    }
};