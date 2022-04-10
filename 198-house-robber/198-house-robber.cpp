class Solution {
public:
    int rob(vector<int>& nums) {
            int dp[110];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    for(int i = 3; i < nums.size() + 3; ++i) {
        dp[i] = max(dp[i - 3] + nums[i - 3], dp[i - 2] + nums[i - 3]);
    }
    int mmax = 0;
    for(int i = 0; i < nums.size() + 3; ++i) {
        mmax = max(mmax, dp[i]);
    }
        
        return mmax;
    }
};