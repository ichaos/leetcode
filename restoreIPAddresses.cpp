/**
 * Restore IP Addresses
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
class Solution {
private:
    bool isValid(string &s, int i) {
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '5')) return true;
        
        if (s[i] == '2' && s[i + 1] == '5' && s[i + 2] <= '5') return true;
        
        return false;
    }
    void _restoreIpAddresses(vector<string> &ret, string &s, int i, int l, string instance) {
        if (i == s.size() && l == 4) {
            ret.push_back(instance);
        } else if (i >= s.size() || l >= 4) return;
        
        if (l != 0) {
            instance += '.';
        }
        
        //eat one character
        _restoreIpAddresses(ret, s, i + 1, l + 1, instance + s[i]);
        //eat two
        if (i + 2 <= s.size() && s[i] != '0')
            _restoreIpAddresses(ret, s, i + 2, l + 1, instance + s[i] + s[i + 1]);
        
        if (i + 3 <= s.size() && isValid(s, i))
            _restoreIpAddresses(ret, s, i + 3, l + 1, instance + s[i] + s[i + 1] + s[i + 2]);
        
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<string> ret;
       string ins;
       
       _restoreIpAddresses(ret, s, 0, 0, ins);
       
       return ret;
    }
};