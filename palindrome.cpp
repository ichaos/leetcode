class Solution {
private:
    vector<vector<string> > res;
    
    int isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i])
                return 0;
        }
        
        return 1;
    }
    
    void _partition(string s, vector<string> vec) {
        int i = 1;
        while (i <= s.size()) {  
            if (isPalindrome(s.substr(0, i))) {
                vector<string> nvec(vec);
                nvec.push_back(s.substr(0, i));
                if (i == s.size()) {
                    res.push_back(nvec);
                    return;
                }
                _partition(s.substr(i, s.size() - i), nvec);            
            }
            i++;
        }        
    }    
    
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        res.clear();
        vector<string> vec;
        _partition(s, vec);
        return res;
    }
};
