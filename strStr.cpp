/**
 * Implement strStr()
 * Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
class Solution {
private:
    bool isEqual(char *a, char *b) {
        while (*b != '\0') {
            if (*a++ != *b++) return false;
        }
        return true;
    }
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (needle == NULL || haystack == NULL) return NULL;
        if (*needle == '\0') return haystack;
        char *h = haystack;
        while (*h != '\0') {
            if (isEqual(h, needle))
                return h;
            h++;
        }
        return NULL;
    }
};
