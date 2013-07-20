/**
 * Length of Last Word
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
 */
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *ss = s;
        int p = 0;
        int l = 0;
        while (*ss != '\0') {
            if (*ss == ' ') {
                p = (l != 0) ? l : p;
                l = 0;
            } else
                l++;
            ss++;
        }
        return (l == 0) ? p : l;
    }
};