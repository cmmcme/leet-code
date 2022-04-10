class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        
        int dp[110];
        memset(dp, -1, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int mmax = dp[1];;
        for(int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            mmax = max(mmax, dp[i]);
        }
        
        return mmax;
    }
};