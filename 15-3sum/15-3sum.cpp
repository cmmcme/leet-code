class Solution {
public:
    vector<vector<int>> ret;
    void bSearch(vector<int> vec, int l, int r, int target) {
    while (l < r) {
        int sum = target + vec[l] + vec[r];
        
        if(sum > 0) r--;
        else if (sum < 0) l++;
        else {
            vector<int> res;
            res.push_back(target);
            res.push_back(vec[l]);
            res.push_back(vec[r]);
            ret.push_back(res);
            l++;
            while(vec[l] == vec[l-1] && l < r) l++;
        }
    }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); ++i) {
        if(i!= 0 && nums[i] == nums[i-1]) {
            continue;
        }
        bSearch(nums, i + 1, nums.size() - 1, nums[i]);
    }
        
        return ret;
    }
};