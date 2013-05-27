/**
 * Longest Consecutive Sequence
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       // find the biggest number
       map<int, int> hmap;
       int longest = 0;
       int curleng = 0;
       
       for (int i = 0; i < num.size(); i++) {
           hmap[num[i]] = 1;
       }
       
       for (int i = 0; i < num.size(); i++) {
           curleng = 0;
           int val = num[i];
           if (hmap.find(val) == hmap.end()) continue;
           
           curleng = 1;
           while (1) {
               val++;
               if (hmap.find(val) == hmap.end()) break;
               curleng++;
               hmap.erase(val);               
           }
           val = num[i];
           while (1) {
               val--;
               if (hmap.find(val) == hmap.end()) break;
               curleng++;
               hmap.erase(val);               
           }
           if (longest < curleng) longest = curleng;
       }
       return longest;
    }
};