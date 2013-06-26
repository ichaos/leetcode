class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int maxArea = 0;
    stack<int> s;
    height.push_back(0);
    int i = 0; 
    while (i < height.size()) {
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i++);
        } else {
            int t = s.top();
            s.pop();
            maxArea = max(maxArea, height[t] * ((s.empty()) ? i : i - s.top() - 1));
        }
    }
    return maxArea;
}
};