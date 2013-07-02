/**
 * Reverse Integer
 *
 * Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
 */

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        bool negative = (x < 0);
        int t = x;
        //int t = x * (negative ? -1 : 1);
        while (t >= 10 || t <= -10) {
            v.push_back(t % 10);
            t = t / 10;
        }
        v.push_back(t);
        
        t = 0;
        for (int i = 0; i < v.size(); i++) {
            t = t * 10 + v[i];
            if (negative && t > 0 || !negative && t < 0) return 0;
        }
        return t;
        //return t * ((negative) ? 1 : -1);
    }
};