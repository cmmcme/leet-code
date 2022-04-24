class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if(res == nums.size()) return res;
        
        return nums[res] >= target? res : res + 1;
    }
};