class Solution {
public:
    int dp[10010];
    int coinChange(vector<int>& coins, int amount) {
        for(int i = 0; i <= amount; ++i) dp[i] = 10010;
        dp[0] = 0;
        for(int i = 0; i < coins.size(); ++i) {
            int coin = coins[i];
            
            for(int j = coin; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        return dp[amount] == 10010? -1 : dp[amount];
    }
};