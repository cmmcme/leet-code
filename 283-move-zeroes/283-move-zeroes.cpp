class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ret;
        int lastZeroIdx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) continue;
            
            int temp = nums[i];
            nums[i] = nums[lastZeroIdx];
            nums[lastZeroIdx] = temp;
            lastZeroIdx++;
        }
    }
};