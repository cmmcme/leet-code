class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); ++i) totalSum += nums[i];
        
        if(totalSum % 2 != 0) return false; // because partitioned into "two" subsets 
        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); ++i) {
            for(int now = target; now >= 0; --now) {
                if(now - nums[i] < 0) continue;
                if(dp[now - nums[i]] == false) continue;
                dp[now] = true;
                
                if(now == target) return true;
            }
        }

        return dp[target];
    }
};