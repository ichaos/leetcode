/**
 * Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        stack<char> a; //()
        stack<char> b; //{}
        stack<char> c; //[]
        
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case '(':
                a.push('('); break;
                
                case ')':
                if (!a.size() || a.top() != '(') return false;
                a.pop(); break;
                
                case '{':
                a.push('{'); break;
                
                case '}':
                if (!a.size() || a.top() != '{') return false;
                a.pop(); break;
                
                case '[':
                a.push('['); break;
                
                case ']':
                if (!a.size() || a.top() != '[') return false;
                a.pop(); break;
                
                default: break;
            }
        }
        
        if (a.size() || b.size() || c.size()) return false;
        
        return true;
    }
};
