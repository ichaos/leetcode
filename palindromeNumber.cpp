/**
 * Palindrome Number
 * Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int tmp = x;
        int l = 0;
        /*
         * check in the future: whether there's a number its reverse number will overflow to the palindrome number, i.e. itself?
         * try to find one or prove it doesn't exist.
         */
        if (x < 0) {
            while (tmp < 0) {
                l = l * 10 + (tmp % 10);
                tmp = tmp / 10;
            }
            //l++;
        } else {
            while (tmp > 0) {
                l = l * 10 + (tmp % 10);
                tmp = tmp / 10;
           }
        }
        
        
        if (l == x) {
            return true;
        } else {
            return false;
        }
    }
};