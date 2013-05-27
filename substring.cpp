/**
 * Given a string, find the length of the longest substring 
 * without repeating characters. 
 * For example, the longest substring without repeating letters 
 * for "abcabcbb" is "abc", which the length is 3. 
 * For "bbbbb" the longest substring is "b", with the length of 1.
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() < 1)
    		return 0;

		int li = 0;
		int slength = 0;        
		int endi = 0;
		int elength = 0;

		map<char, int> cm;
		cm[s[0]] = 0;

		slength = 1;
		elength = 1;

		char c;
		for (int i = 1; i < s.length(); i++) {
			c = s[i];
			if (li == endi) {
				if (cm.find(c) == cm.end()) {
					cm[c] = i;
					slength++;
					elength++;
				} else {
					if (cm[c] >= li) {
						endi = cm[c] + 1;
						elength = i - cm[c];
					} else {
						slength++;
						elength++;
					}
					cm[c] = i;
				}
			} else {
				if (cm.find(c) == cm.end()) {
					cm[c] = i;
					elength++;
				} else {
					if (cm[c] >= endi) {
						endi = cm[c] + 1;
						elength = i - cm[c];
					} else {
						elength++;
					}
                    cm[c] = i;
				}
				if (elength >= slength) {
					li = endi;
					slength = elength;
				}
			}
		}
		return slength;
    }
};