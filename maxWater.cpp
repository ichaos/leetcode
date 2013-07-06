/**
 * Container With Most Water
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
 */

    class Solution {
private:
    struct region {
        int left;
        int right;
        region(int l, int r) : left(l), right(r) {}
        region() {} ;
    };
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, region> s;
        int max = 0;
        for (int i = 0; i < height.size(); i++) {
            if (s.find(height[i]) == s.end()) {
                region r(i, i);
                s[height[i]] = r;
                s[height[i]].left = i;
                s[height[i]].right = i;
            } else {
                s[height[i]].right = i;
            }
        }
        
        int ml = height.size();
        int mr = 0;
        int area = 0;
        for (map<int, region>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
            if (ml > it->second.left) ml = it->second.left;
            if (mr < it->second.right) mr = it->second.right;
            area = (mr - ml) * it->first;
            if (area > max) max = area;
        }
        return max;
    }

    //better solution with greedy algorithm
    /* Proven:
     * 这个问题等价于，对于任何一个数组中的值，找到离他最远的不小于它的值，
     * 它们组成的面积就是这个值对应的矩形的最大面积，
     * 找到所以数组中值所对应的矩形面积，取最大值就是解了。
     * 
     */
    int maxAreaO(vector<int> height) {
        int i = 0;
        int j = height.size();
        int max = 0;
        int area = 0;
        while (i < j) {
            area = min(height[i], height[j]) * (j - i);
            if (max < area) max = area;
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
};