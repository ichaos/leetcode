/*
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
 */
class Solution {
private:
    void _fullJustify(vector<string> &ret, vector<string> &words, int i, int L) {
        int n = words.size();
        if (i >= n) return;
        int s = i;
        int cnt = words[s].size();
        s++;
        while (s < n) {
            if (cnt + words[s].size() + s - i <= L) {
                cnt += words[s].size();
                s++;
            } else {
                break;
            }
        }
        string ss;
        if (s == n) { //over
            for (int j = i; j < s; j++) {
                ss += words[j];
                if (j == s - 1) {
                    string space(L - cnt - (s - i - 1), ' ');
                    ss += space;
                } else
                    ss += ' ';
            }
            ret.push_back(ss);
            return;
        }
        
        if (s == i + 1) {
            ss += words[i];
            string sps(L - cnt, ' ');
            ss += sps;
            ret.push_back(ss);
        } else {
            int spaceslot = s - i - 1;
            string spaces[spaceslot];
            for (int j = 0; j < L - cnt; j++) {
                spaces[j % spaceslot] += ' ';
            }
            int wc = s - i;
            for (int j = i; j < s; j++) {
                ss += words[j];
                if (j == s - 1) continue;
                else {
                    ss += spaces[j - i];
                }
            }
            ret.push_back(ss);
        }        
        _fullJustify(ret, words, s, L);
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if (words.size() < 1 || words[0].size() < 1) {
            string s;
            if (L > 0) {
                string tmp(L, ' ');
                s = tmp;
            }
            ret.push_back(s);
            return ret;
        }
        _fullJustify(ret, words, 0, L);
        return ret;
    }
};