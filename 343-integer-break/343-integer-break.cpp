class Solution {
public:    
    int dp[60];
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;

        for(int num = 3; num <= n; ++num) {
            for(int i = 1; i < num; ++i) {
                int currentMax = max(dp[num - i], num - i);
                dp[num] = max(dp[num], currentMax * i);
            }
        }
        return dp[n];
    }
};