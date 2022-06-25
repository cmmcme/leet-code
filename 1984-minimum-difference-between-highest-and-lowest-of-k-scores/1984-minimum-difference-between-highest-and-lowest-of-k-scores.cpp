class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());

        int mmin = INT_MAX;
        for(int i = k - 1; i < nums.size(); ++i) {
            mmin = min(abs(nums[i - k + 1] - nums[i]), mmin);
        }
        return mmin;
    }
};