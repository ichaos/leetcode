/**
 * Letter Combinations of a Phone Number
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //vector<vector<char> > phone;
        vector<string> res;
        
        char phone[][4] = {
            {'a', 'b', 'c', '\0'},
            {'d', 'e', 'f', '\0'},
            {'g', 'h', 'i', '\0'},
            {'j', 'k', 'l', '\0'},
            {'m', 'n', 'o', '\0'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v', '\0'},
            {'w', 'x', 'y', 'z'}
        };
        
        int n = digits.size();
        
        if (n < 1) {
            res.push_back("");
            return res;
        };
        
        queue<string> q;
        string first = "";
        q.push(first);
        
        while (!q.empty()) {
            string tmp = q.front();            
            int i = tmp.size();
            if (i == digits.size()) break;
            int d = digits[i] - '2';

            q.push(tmp.insert(i, 1, phone[d][0]));
            tmp = q.front();
            q.push(tmp.insert(i, 1, phone[d][1]));
            tmp = q.front();
            q.push(tmp.insert(i, 1, phone[d][2]));
            if (d == 5 || d == 7) {
                tmp = q.front();
                q.push(tmp.insert(i, 1, phone[d][3]));
            }
            q.pop();
        }
        
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
