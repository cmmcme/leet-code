class Solution {
public:
    int dp[110][110];

int func(int j, int i) {
    if(j == 0 || i == 0) {
        dp[j][i] = 1;
        return 1;
    }
    
    if(dp[j][i] != 0) return dp[j][i];
    
    return dp[j][i] = func(j - 1, i) + func(j, i - 1);
}
    
    int uniquePaths(int m, int n) {
        dp[0][0] = 1;
    
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(j == 0 || i == 0) {
                    dp[j][i] = 1;
                    continue;
                }
                if(dp[j][i] != 0) continue;
                
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[m-1][n-1];
    }
};