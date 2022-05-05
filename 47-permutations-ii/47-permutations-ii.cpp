class Solution {
public:
    int count[22];
    vector<int> vec;
    vector<vector<int>>res;
    
    void dfs(vector<int>& nums) {
        if(vec.size() == nums.size()) {
            res.push_back(vec);
            return;
        }
        for(int i = 0; i < 22; ++i) {
            if(count[i] == 0) continue;
            
            count[i]--;
            vec.push_back(i - 10);
            dfs(nums);
            vec.pop_back();
            count[i]++;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            count[nums[i] + 10]++;
        }
        
        dfs(nums);
        return res;
    }
};