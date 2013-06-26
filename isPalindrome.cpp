class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) {
            return true;
        }
        
        //if (s.size() == 1) return true;
        
        //char buf[s.size()];
        int i = 0;
        int j = s.size() - 1;
        
        while (i <= j) {
            if (!isalnum(s[i])) {
                i++; continue;
            }
            if (!isalnum(s[j])) {
                j--; continue;
            }
            
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};