class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numsSet;
        for(int i = 0; i < nums.size(); ++i) {
            if(numsSet.find(nums[i]) == numsSet.end()) {
                numsSet.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};