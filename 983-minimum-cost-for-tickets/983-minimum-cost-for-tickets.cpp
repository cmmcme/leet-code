class Solution {
public:
    
    bool calander[370] = {false};
    int dp[370];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < days.size(); ++i) calander[days[i]] = true;
        dp[0] = 0;
        for(int i = 1; i <= days[days.size() - 1]; ++i) {
            if(!calander[i]) dp[i] = dp[i - 1];
            int res1 = dp[i - 1] + costs[0];
            int res2 = dp[i - 7 < 0 ? 0 : i - 7] + costs[1];
            int res3 = dp[i - 30 < 0 ? 0 : i - 30] + costs[2];
            dp[i] = min(dp[i], min(res1, min(res2, res3)));
        }
        return dp[days[days.size() - 1]];
    }
};