class Solution {
public:
    int dp[10010];
    int jump(vector<int>& nums) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int jump = nums[i];
            int limitJ = jump + i > nums.size() -1 ? nums.size() -1 : jump + i;
            for(int j = i + 1; j <= limitJ; ++j) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        
        return dp[nums.size() -1];
    }
};