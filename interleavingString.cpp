/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */
class Solution {
private:
    bool _isInterleave(string &s1, int i1, string &s2, int i2, string &s3, int i3) {
        if (i3 == s3.size()) return true;
        
        if (s1.size() > i1 && s1[i1] == s3[i3])
            if (_isInterleave(s1, i1 + 1, s2, i2, s3, i3 + 1))
                return true;
            
        if (s2.size() > i2 && s2[i2] == s3[i3])
            if (_isInterleave(s1, i1, s2, i2 + 1, s3, i3 + 1))
                return true;
        return false;
    }
    struct decision {
        int i;
        int j;
        int m;
        decision(int ii, int jj, int mm) : i(ii), j(jj), m(mm) {}
    };
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        if (s1.size() + s2.size() != s3.size()) return false;
        
        multiset<pair<int, int> > cache;
        stack<decision> s;
        int m = 0;
        int i = 0;
        int j = 0;
        while (m < s3.size()) {
            if (i == s1.size()) {
                if (s2[j] == s3[m]) {
                    j++;
                    m++;
                    continue;
                } else {
                    if (!s.empty()) {
                        decision d = s.top();
                        i = d.i;
                        j = d.j + 1;
                        m = d.m + 1;
                        s.pop();
                        cache.insert(make_pair(i, d.j));
                    } else return false;
                }
            } else if (j == s2.size()) {
                if (s1[i] == s3[m]) {
                    i++;
                    m++;
                    continue;
                } else {
                    if (!s.empty()) {
                       decision d = s.top();
                       i = d.i;
                       j = d.j + 1;
                       m = d.m + 1;
                       s.pop();
                       cache.insert(make_pair(i, d.j));
                    } else return false;
                }               
            } else {
                if (s1[i] == s3[m] && s2[j] == s3[m]) {
                    if (cache.find(make_pair(i, j)) != cache.end()) {
                        if (!s.empty()) {
                            decision d = s.top();
                            i = d.i;
                            j = d.j + 1;
                            m = d.m + 1;
                            s.pop();
                            cache.insert(make_pair(i, d.j));
                        } else return false;
                        continue;
                    }
                    decision d(i, j, m);
                    s.push(d);
                    i++; m++;
                } else if (s1[i] == s3[m]) {
                    i++;
                    m++;
                } else if (s2[j] == s3[m]) {
                    j++;
                    m++;
                } else {
                    if (!s.empty()) {
                       decision d = s.top();
                       i = d.i;
                       j = d.j + 1;
                       m = d.m + 1;
                       s.pop();
                       cache.insert(make_pair(i, d.j));
                    } else return false;
                }
            }
            //if (s.empty()) return false;
        }
        
        return true;
        //return _isInterleave(s1, 0, s2, 0, s3, 0);
    }
};