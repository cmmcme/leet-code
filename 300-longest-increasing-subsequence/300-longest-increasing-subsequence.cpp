class Solution {
public:
    int dp[2550] = {-1};
    
    int lengthOfLIS(vector<int>& nums) {
        int mmax = 1;
        dp[0] = 1;
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mmax = max(mmax, dp[i]);
        }
        
        return mmax;
    }
};