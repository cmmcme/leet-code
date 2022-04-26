class Solution {
public:
    int dp[5050] = {0};
    int change(int amount, vector<int>& coins) {
        dp[0] = 1;
        for(int i = 0 ; i < coins.size(); ++i) {
            int coin = coins[i];
            dp[coin] += 1;
            for(int j = coin + 1; j <= amount; ++j) {
                if(dp[j - coin] != 0) {
                    dp[j] += dp[j-coin];
                }
            }
        }
        
        return dp[amount];
    }
};