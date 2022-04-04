class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
    if(nums.size() == 1) return nums[0];
    
    vector<int> dp;
    dp.resize(nums.size() + 1);

    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < nums.size(); ++i) {
        if(dp[i - 1] + nums[i] > nums[i]) {
            dp[i] = dp[i - 1] + nums[i];
        } else {
            dp[i] = nums[i];
        }
        res = max(res, dp[i]);
    } 
        return res;
    }
};