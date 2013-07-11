/**
 * Next Permutation
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */

class Solution {
private:
    bool _nextPermutation(vector<int> &v, int i, int max) {
        int n = v.size();
        if (i == n - 1) {
            return false;
        }
        /*
        if (i == n - 2) {
            if (v[i] < v[i + 1]) {
                //swap them and return true;
                int tmp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = tmp;
                return true;
            } else {
                return false;
            }
        }
        */
        
        if (v[i] == max) {
           //find next max
           max = v[i + 1];
           for (int j = i + 2; j < n; j++) {
               if (max < v[j]) max = v[j];
           }
           if (_nextPermutation(v, i + 1, max)) return true;
           return false;
        } else {
           if (_nextPermutation(v, i + 1, max)) return true;
           //next permutation: max + sorted remaining numbers
            //find next number
            int tmp = max;
            int pos = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (v[j] > v[i] && tmp > v[j]) {
                    tmp = v[j];
                    pos = j;
                }
            }
            //swap 
            v[pos] = v[i];
            v[i] = tmp;
            sort(v.begin() + i + 1, v.end());
            return true;
        }
    }
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        
        if (n < 1) return;
        
        //find max
        int max = num[0];
        for (int i = 1; i < n; i++) {
            if (max < num[i]) max = num[i];
        }
        
        if (_nextPermutation(num, 0, max)) return;
        sort(num.begin(), num.end());
    }
};