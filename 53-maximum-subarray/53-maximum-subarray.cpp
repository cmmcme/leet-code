class Solution {
public:
    int maxSubArray(vector<int>& nums) {        
    if(nums.size() == 1) return nums[0];
        
        int sum = 0;
        int res = -987654321;
        for(int i = 0; i < nums.size(); ++i) {
            if(sum < 0) sum = 0;
            sum = sum + nums[i];
            res = max(res, sum);
        }
        return res;
    }
};