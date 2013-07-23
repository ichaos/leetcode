/**
 * Valid Number
 * Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */
class Solution {
private:
    bool _isPost(const char *s) {
        bool count = false;
        if (*s == '+' || *s == '-') {
            s++;
        }
        
        while (*s != '\0') {
            if (*s >= '0' && *s <= '9') {
                count = true;
                s++;
            } else break;
        }
        while (*s != '\0') {
            if (*s != ' ') return false;
            s++;
        }
        return count;
    }
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool abb = false;
        bool decimal = false;
        bool isNum = false;
        bool positive = false;
        bool count = false;
        
        char prev = '\0';
        
        while (*s != '\0') {
            if (*s == ' ') {
                if (count) {
                    s++;
                    while (*s != '\0') {
                        if (*s != ' ') return false;
                        s++;
                    }
                } else
                    s++;
            } else if (*s == 'e') {
                if (!isNum) return false;
                return _isPost(++s);
            } else if (*s >= '0' && *s <= '9') {
                isNum = true;
                count = true;
                s++;
            } else if (*s == '.') {
                if (decimal) return false;
                decimal = true;
                count = true;
                s++;
            } else if (*s == '+' || *s == '-') {
                if ((prev != ' ' && prev != '\0') || positive) return false;
                positive = true;
                count = true;
                s++;
            } else
                return false;
            prev = *(s - 1);
        }
        return isNum;
    }
};