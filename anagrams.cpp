/**
 * Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.


 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, vector<string> > ht;
        vector<string> v;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            ht[s].push_back(strs[i]);
        }
        
        map<string, vector<string> >::iterator it;
        for (it = ht.begin(); it != ht.end(); it++) {
            if (it->second.size() > 1) {
                v.insert(v.begin(), it->second.begin(), it->second.end());
            }
        }
        return v;
    }
};