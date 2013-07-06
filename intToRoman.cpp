/**
 * Integer to Roman
 * Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string res = "";
        
        if (num >= 1000) {
            res += 'M';
            res += intToRoman(num - 1000);
            return res;
        }
        if (num >= 900) {
            res += "CM";
            res += intToRoman(num - 900);
            return res;
        }
        if (num >= 500) {
            res += "D";
            res += intToRoman(num - 500);
            return res;
        }
        if (num >= 400) {
            res += "CD";
            res += intToRoman(num - 400);
            return res;
        }
        if (num >= 100) {
            res += 'C';
            res += intToRoman(num - 100);
            return res;
        }
        if (num >= 90) {
            res += "XC";
            res += intToRoman(num - 90);
            return res;
        }
        if (num >= 50) {
            res += 'L';
            res += intToRoman(num - 50);
            return res;
        }
        if (num >= 40) {
            res += "XL";
            res += intToRoman(num - 40);
            return res;
        }
        if (num >= 10) {
            res += 'X';
            res += intToRoman(num - 10);
            return res;
        }
        if (num >= 9) {
            res += "IX";
            res += intToRoman(num - 9);
            return res;
        }
        if (num >= 5) {
            res += 'V';
            res += intToRoman(num - 5);
            return res;
        }
        if (num >= 4) {
            res += "IV";
            res += intToRoman(num - 4);
            return res;
        }
        if (num >= 1) {
            res += 'I';
            res += intToRoman(num - 1);
            return res;
        }
        return res;
    }
};