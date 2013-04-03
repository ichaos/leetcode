#include <queue>
#include <utility>

class Solution {
private:
    int isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i])
                return 0;
        }
        
        return 1;
    }
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<pair<string, vector<string> > > q;
        vector<string> vec;
        q.push(make_pair(s, vec));
        
        while (!q.empty()) {
            string s = q.front().first; 
            int i = 0;
            while (i <= s.size()) {
                if (isPalindrome(s.substr(0, i))) {
                    vector<string> nvec(q.front().second);
                    nvec.push_back(s.substr(0, i));
                    q.push(make_pair(s.substr(i, s.size() - i), nvec));
                    if (i == s.size()) //first match
                        return nvec.size() - 1;
                }
                i++;
            }
            q.pop();
        }
    }
};
