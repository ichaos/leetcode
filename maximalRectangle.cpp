/**
 * Maximal Rectangle
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if (m < 1) return 0;
        int n = matrix[0].size();
        
        vector<int> height(n, 0);
        //as a stack
        deque<int> s;
        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            //s.clear();
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
                if (s.empty()) {
                    s.push_back(j);
                } else {
                    int prev = s.back();
                    // calculate previous
                    while (!s.empty() && height[j] < height[s.back()]) {
                        prev = s.back();
                        s.pop_back();
                        int area = height[prev] * (s.empty() ? j : j - s.back() - 1);
                        maxarea = std::max(maxarea, area);
                    }
                    s.push_back(j);
                }                
            }
            while (!s.empty()) {
                int prev = s.back();
                s.pop_back();
                int area = height[prev] * (s.empty() ? n : n - s.back() - 1);
                maxarea = std::max(maxarea, area);
            }
        }
        return maxarea;
    }
};