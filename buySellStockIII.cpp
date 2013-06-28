/**
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() < 2) return 0;
        priority_queue<int> maxPros;
        maxPros.push(0);
        maxPros.push(0);
        int pro = 0;
        int buy = prices[0];
        int drop = 0;
        int shadow = 0;
        int max = 0;
        int dmax = 0;
        int tmp = 0;
        int down = 0;
        int high = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            tmp = prices[i - 1] - buy + drop;
            if (tmp > dmax) dmax = tmp;
            if (prices[i] <= buy) {    
                buy = prices[i];
                maxPros.push(pro);
                pro = 0;
                drop = 0;
                shadow = 0;
                down = 0;
                high = prices[i];
            } else {
                tmp = prices[i] - buy;
                if (tmp > pro) {
                    pro = tmp;
                }
                
                if (high < prices[i])
                    high = prices[i];
                
                tmp = high - prices[i];
                if (tmp > shadow)
                    shadow = tmp;
                if (tmp > drop)
                    drop = tmp;
            }
            if (max < pro) {
                max = pro;
                drop = shadow;
                tmp = prices[i] - buy + drop;
                if (tmp > dmax) dmax = tmp;
            }
        }
        if (prices[prices.size() - 1] > buy) {
            tmp = prices[prices.size() - 1] - buy + drop;
            if (tmp > dmax) dmax = tmp;
        }
        
        maxPros.push(pro);
        pro = 0;
        pro += maxPros.top();
        maxPros.pop();
        pro += maxPros.top();
        
        if (dmax > pro)
            pro = dmax;
        
        return  pro;
    }
};

int main() {
    Solution s;
    int arr[] = {1,7,2,4};
    std::vector<int> v(arr, arr + 4);
    cout << s.maxProfit(v) << endl;
}