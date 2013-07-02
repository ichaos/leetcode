/**
 * ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        if (nRows < 2) return s;
        int n = s.size();
        if (n < 3) return s;
        
        vector<char> v[nRows];
        
        bool down = true;

        for (int r = 0, j = 0; j < n;) {
            if (down && r < nRows) {
                v[r++].push_back(s[j++]);
            } else if (!down && r >= 0) {
                v[r--].push_back(s[j++]);
            } else {
                r += (down) ? -2 : 2;
                down = !down;
            }
        }
        
        string t;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                t += v[i][j];
            }
        }
        return t;
    }
};