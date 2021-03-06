/**
 * Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 1) return 0;
        if (n < 2) return 1;
        if (n < 3) return 2;
        int dp[n];
        dp[0] = 1;
        dp[1] = 1 + 1;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n - 1];
    }
};