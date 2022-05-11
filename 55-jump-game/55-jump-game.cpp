class Solution {
public:
    bool canJump(vector<int>& nums) {
        int aim = nums.size() - 1;
         for(int i = nums.size() - 1; i >= 0; --i) {
             if(i + nums[i] >= aim) aim = i;
         }
        
        return aim == 0;
    }
};