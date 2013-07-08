/**
 * Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
 */
class Solution {
private:
    struct node {
        string s;
        int left;
        int right;
        node(string n, int l, int r) : s(n), left(l), right(r) {}
    };
    
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> v;
        if (n < 1) return v;
        
        queue<node> q;
        node nd("(", 1, 0);
        q.push(nd);
        
        while (!q.empty()) {
            node tmp = q.front();
            //q.pop();
            
            if (tmp.left == n) {
                if (tmp.right < tmp.left) {
                    tmp.s += ")";
                    tmp.right++;                    
                }
                if (tmp.right == n)
                    v.push_back(tmp.s);
                else
                    q.push(tmp);
                //q.pop();
                //continue;
            } else if (tmp.left < n) {
                tmp.s += "(";
                tmp.left++;
                q.push(tmp);
                tmp = q.front();
                if (tmp.left > tmp.right) {                    
                    tmp.s += ")";
                    tmp.right++;
                    q.push(tmp);
                }
            }
            
            q.pop();
        }
    }
};
