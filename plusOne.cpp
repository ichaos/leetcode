/**
 * Given a number represented as an array of digits, plus one to the number.
 */
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = digits.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int tmp = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + carry) % 10;
            carry = tmp;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        //vector<int> ret(digits.rbegin(), digits.rend());
        return digits;
    }
};