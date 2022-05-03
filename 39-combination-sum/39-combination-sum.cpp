class Solution {
public:
    
int dp[550] = {0};
vector<vector<int>> resultVec;
bool dyna(vector<int>& candidates, int target) {
    dp[0] = 1;
    for(int i = 0; i < candidates.size(); ++i) {
        int coin = candidates[i];
        for(int j = coin; j <= target; ++j) {
            dp[j] += dp[j - coin];
        }
    }
    if(dp[target] == 0) {
        return false;
    }
    return true;
}

void func(vector<int>& candidates, int target, vector<int>& res, int lastIndex) {
    if(target == 0) {
        resultVec.push_back(res);
        return ;
    }
    
    if(resultVec.size() >= 150) return ;
    
    for(int i = lastIndex; i < candidates.size(); ++i) {
        int coin = candidates[i];
        if(target - coin < 0) continue;
        if(dp[target - coin] == 0) continue;
        
        res.push_back(coin);
        func(candidates, target - coin, res, i);
        res.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(!dyna(candidates, target)) return resultVec;
    
    /*
     백트래킹 시장
     */
    vector<int> vec;

    func(candidates, target, vec, 0);
    return resultVec;
}
};