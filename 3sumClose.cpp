/**
 * 3Sum Closest
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(3);
    int s = num.size();
	if (s < 3) return 0;
	sort(num.begin(), num.end());
	int min = INT_MAX;
	for (int j = 0; j < s; j++) {
		int m = j + 1;
		int n = s - 1;
		//num[m] + num[n] + num[j] = target
		//so sum = num[m] + num[n] = target - num[j]
		int sum = target - num[j];

		while (m < n) {
			int tmp = num[m] + num[n] - sum;
			if (tmp == 0) {
				//find answer
				res[0] = num[j];
				res[1] = num[m];
				res[2] = num[n];
				return target;
			}
			if (abs(tmp) < min) {
				min = abs(tmp);
				res[0] = num[j];
				res[1] = num[m];
				res[2] = num[n];
			}
			if (tmp < 0) {
				m++;
			} else {
				n--;
			}
		}
	}
	return res[0] + res[1] + res[2];
    }
};