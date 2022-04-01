class Solution {
public:
    int dp[1010];
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0) return 0;
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); ++i) {
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        }
        
        return dp[cost.size() - 1] < dp[cost.size() - 2] ? dp[cost.size() - 1] : dp[cost.size() - 2] ;
    }
};