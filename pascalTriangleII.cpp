/**
 * Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]. 
 * i.e. [C(3,0), C(3,1), C(3,2), C(3,3)]

Note:
Could you optimize your algorithm to use only O(k) extra space?

 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if (rowIndex < 0) return res;        
        
        unsigned long long ans[rowIndex + 1];
        int j = (rowIndex + 2) / 2;
        ans[0] = 1;
        
        for (int i = 1; i < j; i++) {
            ans[i] = ans[i - 1] * (rowIndex - i + 1) / i;
        }
        
        while (j <= rowIndex) {
            ans[j] = ans[rowIndex - j];
            j++;
        }
        
        vector<int> r(ans, ans + rowIndex + 1);
        return r;
    }
};