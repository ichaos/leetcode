/**
 * addBinary
 * Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

class Solution {
private:
    int _addBinary(char a, char b, int carry, string &s) {
        int x = a - '0';
        int y = b - '0';
        
        s += (((x + y + carry) % 2) + '0');
        return (x + y + carry) / 2;
        
    }
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s;
        
        int m = a.size(); 
        int n = b.size();
        
        int l = m > n ? m : n;  
        int carry = 0;
        
        for (int i = 0; i < l; i++) {
            if (i >= m) {
                carry = _addBinary('0', b[n - i - 1], carry, s);
            } else if (i >= n) {
                carry = _addBinary(a[m - i - 1], '0', carry, s);
            } else
                carry = _addBinary(a[m - i - 1], b[n - i - 1], carry, s);
        }
        if (carry) {
            s += '1';
        }
        //reverse
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        return s;
    }
};