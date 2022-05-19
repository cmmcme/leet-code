class Solution {
public:
    int dp[60];
    
    int func(int n) {  
        if(dp[n] != -1) return dp[n];
        
        for(int i = 1; i <= n; ++i) {
            dp[n] = max(dp[n], i * func(n - i));
        }
        return dp[n];
    }
    
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        if(n <= 3) return dp[n];
        func(n + 1);
        return dp[n + 1];
    }
};