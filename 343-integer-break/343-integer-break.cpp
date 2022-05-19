class Solution {
public:
    int dp[60];
    
    int func(int n) {  
        if(dp[n] != -1) return dp[n];
        
        int mmax = 0;
        for(int i = 1; i < n; ++i) {
            int currentMax = max(func(n - i), n - i);
            mmax = max(currentMax * i, mmax);
        }
        return dp[n] = mmax;
    }
    
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        return func(n);
    }
};