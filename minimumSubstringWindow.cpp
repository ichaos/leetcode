/**
 * Minimum Window Substring
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> cm;
        map<char, int> tm;
        int m = S.size();
        int n = T.size();
        
        for (int i = 0; i < n; i++) {
            tm[T[i]]++;
        }
        
        string ws;
        int start = 0;
        int cnt = 0;
        
        for (int i = 0; i < m; i++) {
            if (tm.count(S[i])) {
                cm[S[i]]++;
                if (cm[S[i]] <= tm[S[i]]) cnt++;
                //if (cnt == 1) start = i;
            }
            if (cnt == n) { //find one
                //shrink the window
                //int j = start;
                while (1) {
                    if (cm[S[start]] == 0) start++;
                    else if (cm[S[start]] > tm[S[start]]) {
                        cm[S[start]]--;
                        start++;
                    } else {
                        //start++;
                        cnt--;
                        cm[S[start]]--;
                        break;
                    }
                }
                if (ws.size() == 0 || ws.size() > i - start + 1)
                    ws = S.substr(start, i - start + 1);
                start++;
            }
        }
        return ws;
    }
};