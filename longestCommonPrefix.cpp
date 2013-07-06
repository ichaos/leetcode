/** 
 * Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
class Solution {
private:
    string strCommonPrefix(string a, string b) {
        int l = 0;
        for (int i = 0; i < a.size() && i < b.size(); i++) {
            if (a[i] != b[i]) {
                //l = i - 1;
                break;
            } else
                l++;
        }
        if (l > 0)
            return a.substr(0, l);
        else
            return "";
    }
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() < 1) return "";
        if (strs.size() == 1) return strs[0];

        string prefix = strs[0];
        string tmp = "";
        // by sorting this string array, we can easily find the longest common prefix of any two string
        // among the string array instead of all strings.
        //sort(strs.begin(), strs.end());
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++) {
            if (it + 1 == strs.end()) break;
            tmp = strCommonPrefix(*it, *(it + 1));
            if (prefix.size() > tmp.size()) prefix = tmp;
        }
        
        return prefix;
    }
};