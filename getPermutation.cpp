/**
 * Permutation Sequence
 * getPermutation
 * The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
private:
    int factorial(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }
    void _getPermutation(string &s, vector<int> &num, int k) {
        int n = num.size();
        if (n < 1 || k > factorial(n)) return;

        if (k == factorial(n)) {
            for (int i = n; i > 0; i--) {
                s += ('0' + num[i - 1]);
            }
            return;
        }
        int i = (k - 1) / factorial(n - 1);
        s += (num[i] + '0');
        num.erase(num.begin() + i);
        k -= (i * factorial(n - 1));
        _getPermutation(s, num, k);
    }
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s;        
        vector<int> num(n, 0);
        for (int i = 0; i < n; i++) {
            num[i] = i + 1;
        }
        _getPermutation(s, num, k);
        return s;
    }
};