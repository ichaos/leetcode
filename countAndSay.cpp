/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
 */

class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s;
        if (n == 0) return s;
        s = "1";
        while (n > 1) {
            n--;
            string tmp = s;
            s = "";
            char c = tmp[0];
            int count = 1;
            for (int i = 1; i < tmp.size(); i++) {
                if (tmp[i] == c) {
                    count++;
                } else {
                    s += ('0' + count);
                    s += c;
                    c = tmp[i];
                    count = 1;
                }
            }
            s += ('0' + count);
            s += c;
        }
        
        return s;
    }
};