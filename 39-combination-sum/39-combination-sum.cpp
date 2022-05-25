class Solution {
public:
    vector<vector<int>> resVec;
    int dp[1010];
    bool coinFunc(vector<int>& candidates, int target) {
        dp[0] = 1;
        for(int i = 0; i < candidates.size(); ++i) {
            int coin = candidates[i];
            for(int j = coin; j <= target; ++j) {
                if(dp[j - coin] == 0) continue;
                
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[target];
    }
    
    
    void findCombination(vector<int>& candidates, int target, int index, vector<int>& res) {
        if(target == 0) {
            resVec.push_back(res);
            return ;
        }
        
        for(int i = index; i < candidates.size(); ++i) {
            if(target - candidates[i] < 0) continue;
            if(dp[target - candidates[i]] == 0) continue;
            res.push_back(candidates[i]);
            findCombination(candidates, target - candidates[i], i, res);
            res.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(!coinFunc(candidates, target)) return resVec;
        vector<int> vec;
        findCombination(candidates, target, 0, vec);
        
        return resVec;
    }
};