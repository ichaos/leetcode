class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea = 0;
        int n = height.size();
        int left, right;
        int area;
        for (int i = 0; i < n; i++) {
            //find left boundary
            left = i - 1;
            while (left >= 0) {
                if (height[left] >= height[i]) {
                    left--;
                } else {
                    break;
                }
            }
            left++;
            right = i + 1;
            while (right < n) {
                if (height[right] >= height[i]) {
                    right++;
                } else {
                    break;
                }
            }
            right--;
            area = (right - left + 1) * height[i];
            if (area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};