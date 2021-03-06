/**
 * String to Integer (atoi)
 * Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *sp = str;
        bool negative = false;
        int v = 0, prev = 0;
        int of = 0;
        while (*sp != '\0' && *sp == ' ') {
            sp++;
        } 
        if (*sp == '+') {
            negative = false;
                sp++;
        } else if (*sp == '-') {
           negative = true;
            sp++;
        }
        while (*sp != '\0') {
            if (*sp <= '9' && *sp >= '0') {
                v = prev * 10;
                if (v / 10 != prev) return (negative ? INT_MIN : INT_MAX);
                prev = v;
                v = prev + ((*sp - '0') * (negative ? -1 : 1));
                sp++;
                if (negative && v > prev || !negative && v < prev)
                    return (negative ? INT_MIN : INT_MAX);
                prev = v;
            } else
                return v;
        }
        return v;
    }
};