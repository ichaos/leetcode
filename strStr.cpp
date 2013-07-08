/**
 * Implement strStr()
 * Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
class Solution {
private:
    int findSlip(char *end, int l, char c) {
        int r = l;
        while (c != *end && r > 0) {
            r--;
            end--;
        }
        return l - r + 1;
    }
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //sunday
        char *hp = haystack;
        char *np = needle;
        
        int l = 0;
        while (*np != '\0') {
            l++;
            np++;
        }
        if (l == 0) return hp;
        np = needle;
        int i = 0;
        while (*hp != '\0') {
            if (*np == '\0') {
                return hp;
            }
            if (*(hp + i) == '\0') return NULL;
            if (*(hp + i) == *np) {
                i++;
                np++;
            } else {
                int step = findSlip(needle + l - 1, l, *(hp + l));
                hp += step;
                np = needle;
                i = 0;
            }
        }

        return NULL;
    }
};
