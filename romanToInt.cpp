/**
 * Roman to Integer
 * Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'M': //M = 1000
                    num += 1000;
                    break;
                case 'D': //D = 500
                    num += 500;
                    break;
                case 'C': // C = 100
                    if (s[i + 1] == 'M') {
                        num += 900;
                        i++;
                        //break;
                    } else if (s[i + 1] == 'D') {
                        num += 400;
                        i++;
                    } else {
                        num += 100;
                    }
                    break;
                case 'L': // L = 50
                    num += 50; break;
                case 'X': // X = 10
                    if (s[i + 1] == 'C') {
                        num += 90; i++;
                    } else if (s[i + 1] == 'L') {
                        num += 40; i++;
                    } else
                        num += 10;
                    break;
                case 'V': // V = 5
                    num += 5; break;
                case 'I':
                    if (s[i + 1] == 'X') {
                        num += 9;
                        i++;
                    } else if (s[i + 1] == 'V') {
                        num += 4;
                        i++;
                    } else
                        num++;
                    break;
                default: break;
            }
        }
        return num;
    }
};