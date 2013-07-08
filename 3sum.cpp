/**
 * 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (num.size() < 3) return res;
	    sort(num.begin(), num.end());
        
        //set<int> sum;

	    for (int j = 0; j < num.size(); j++) {
		    if (j > 0 && num[j - 1] == num[j]) {
			    continue;
		    }
		    int m = j + 1;
		    int n = num.size() - 1;
		    vector<int> tmp;
		    while (m < n) {			    
			    if (num[m] + num[n] + num[j] == 0) {
				    tmp.clear();
				    tmp.push_back(num[j]);
				    tmp.push_back(num[m]);
				    tmp.push_back(num[n]);
				    res.insert(res.begin(), tmp);
                    //res.push_back(tmp);
                    m++;
                    while (m < n && num[m] == num[m - 1])
				        m++;
			    } else if (num[m] + num[n] + num[j] < 0) {
				    m++;
			    } else
				    n--;
		    }
	    }
        //deduplicate
        /*
        for (int i = 1; i < res.size(); i++) {
            if (res[i - 1][0] == res[i][0] && res[i - 1][1] == res[i][1] &&
                res[i - 1][2] == res[i - 1][2]) {
                res.erase(res.begin() + i - 1);
                i--;
            }
        }
        //*/
	    return res;
    }
};

int main() {
	int arr[] = {-1, 0, 1, 2, -1, -4};
	vector<int> v(arr, arr + 6);
	std::vector<std::vector<int> > r = threeSum(v);
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}