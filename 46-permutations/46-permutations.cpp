class Solution {
public:
    bool visited[10] = {false};
    vector<vector<int>> reason;
    vector<int> res;
    void dfs(vector<int>& nums) {
        if(res.size() == nums.size()) {
            reason.push_back(res);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(visited[i]) continue;
            visited[i] = true;
            res.push_back(nums[i]);
            dfs(nums);
            visited[i] = false;
            res.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {        
        dfs(nums);
        
        return reason;
    }
};