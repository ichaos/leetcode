/**
 * 4Sum
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
 */

class Solution {
private:
    vector<vector<int> > threeSum(vector<int> &num, int target) {
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
			    if (num[m] + num[n] + num[j] == target) {
				    tmp.clear();
				    tmp.push_back(num[j]);
				    tmp.push_back(num[m]);
				    tmp.push_back(num[n]);
				    res.insert(res.begin(), tmp);
                    //res.push_back(tmp);
                    m++;
                    while (m < n && num[m] == num[m - 1])
				        m++;
			    } else if (num[m] + num[n] + num[j] < target) {
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
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        int n = num.size();
        if (n < 4) return res;
        sort(num.begin(), num.end());
        
        
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int ntarget = target - num[i]; 
            vector<int> v(num.begin() + i + 1, num.end());
            
            vector<vector<int> > threeRes = threeSum(v, ntarget);
            for (int j = 0; j < threeRes.size(); j++) {
                threeRes[j].insert(threeRes[j].begin(), num[i]);
                res.push_back(threeRes[j]);
            }
        }
        
        return res;
    }
};