class Solution {
public:
    int dp[10010];
    int numSquares(int n) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                int square = j * j;
                if(i - square < 0) break;
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
        
        return dp[n];
    }
};