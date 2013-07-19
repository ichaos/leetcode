/**
 * Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.


 */

class Solution {
private:
    bool areAnagrams(string a, string b) {
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        return a == b;
    }
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> v;
        vector<string> depot(strs);
        if (strs.size() <= 1) return v;
        
        string prev;
        bool anagram = false;
        for (int i = 0; i < depot.size(); i++) {
            prev = depot[i];
            anagram = false;
            for (int j = i + 1; j < depot.size(); j++) {
                if (areAnagrams(prev, depot[j])) {
                    //v.push_back(prev);
                    v.push_back(depot[j]);
                    depot.erase(depot.begin() + j);
                    j--;
                    anagram = true;
                }
            }
            if (anagram) {
                v.push_back(prev);
                depot.erase(depot.begin() + i);
                i--;
            }
        }
        return v;
    }
};