#include <queue>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    int isPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i])
                return 0;
        }
        
        return 1;
    }
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> q;         
        int cutedString[s.size() - 1];// = { 0 };
        q.push(s);
        for (int i = 1; i < s.size(); i++)
            cutedString[i] = 0;
        int cut = 0;
        cutedString[0] = 1;
        
        while (!q.empty()) {
            string s = q.front(); 
            int i = 1;
            while (i <= s.size()) {
                if (isPalindrome(s.substr(0, i))) {                             
                    q.push(s.substr(i, s.size() - i));
                    cutedString[cut + 1]++;
                    if (i == s.size()) //first match
                        return cut;
                }                
                i++;
            }
            cutedString[cut]--;
            if (cutedString[cut] == 0)
                cut++;
            q.pop();
        }
    }
};

int main() {
	Solution s;
	cout << "min cut of fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi = " <<
		s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
}
