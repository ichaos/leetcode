#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<char> depot;
        
        int n = s.size();
        
        if (n < 1) return 0;
        
        int max = 0;
        int cur = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                depot.push_back('(');               
            } else if (s[i] == ')') {
                if (depot.size() != 0) {
                   cur += 2;                 
                   depot.pop_back();    
                   if (depot.size() == 0 && cur > max) max = cur;           
                } else {
                    cur = 0;
                }
            }
        }

        cout << "half: " << max << endl;
        
        if (depot.size() == 0 && cur > max) max = cur;
        depot.clear();
        cur = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                depot.push_back(')');
            } else if (s[i] == '(') {
                if (depot.size() != 0) {
                   cur += 2;                 
                   depot.pop_back();    
                   if (depot.size() == 0 && cur > max) max = cur;           
                } else {
                    cur = 0;
                }
            }
        }
        
        if (depot.size() == 0 && cur > max) max = cur;
        
        return max;
    }
};

int main() {
    Solution s;

    cout << s.longestValidParentheses(")()(((())))(") << endl;
    return 0;
}