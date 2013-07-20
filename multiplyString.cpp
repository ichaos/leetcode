/**
 * Multiply Strings
 * Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
 */
class Solution {
private:
    int multiChar(char a, char b, int carry, string &s, int pos) {
        int m = a - '0';
        int n = b - '0';
        int p = m * n + carry;
        int l = s.size();
        if (p == 0) return 0;
        if (pos + 1 > l) {
            s.resize(pos + 1);
            for (int i = l; i < pos + 1; i++) {
                s[i] = '0';
            }
        }
        int cur = s[pos] - '0';
        cur += (p % 10);
        carry = p / 10 + cur / 10;
        s[pos] = cur % 10 + '0';
        return carry;
    }
    
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = num1.size();
        int n = num2.size();
        
        string result;
        
        if (m < 1 || n < 1) return result;
        result = "0";
        
        int carry = 0;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j > -1; j--) {
                carry = multiChar(num1[i], num2[j], carry, result, m - i - 1 + n - 1 - j);
            }
            carry = multiChar('0', '0', carry, result, m - i - 1 + n - 1 + 1);
        }
        
        int i = 0;
        int j = result.size() - 1;
        while (i < j) {
            char c = result[i];
            result[i] = result[j];
            result[j] = c;
            i++;
            j--;
        }
        
        return result;
    }
};