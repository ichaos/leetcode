/**
 * Only work for scrambling once
 */
class Solution {
    private:
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() != s2.length()) return false;
    
        int n = s1.length();
        bool find = false;
        int dif = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                find = true;
                dif = i;
                break;
            }
        }
        if (!find) return true;
        int mid = dif;
        find = false;
        for (int i = dif + 1; i < n; i++) {
            if (s1[dif] == s2[i]) {
                mid = i;
                find = true;
                break;
            }
        }
        if (!find) return false;
        int end = n;
        find = false;
        for (int i = 1; i + mid < n; i++) {
            if (s1[i + dif] != s2[i + mid]) {
                end = i + mid;
                find = true;
                break;
            }
        }
        
        //check s1[dif...] === s2[mid...end - 1] && s1[dif + end - mid...] = s2[dif...mid - 1]
        for (int i = 1; i < end - mid; i++) {
            if (s1[i + dif] != s2[mid + i]) {
                return false;
            }
        }
        for (int i = 1; i < mid - dif; i++) {
            if (s2[i + dif] != s1[dif + end - mid + i]) {
                return false;
            }
        }
        for (int i = end; i < n; i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
};