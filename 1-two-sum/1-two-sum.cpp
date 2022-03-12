class Solution {
public:
    vector<pair<int, int>> pairVector;
    vector<int> res;
    int targetSum;
void bSearch(int l, int r) {
    if(l >= r) return ;
    
    int sum = pairVector[l].first + pairVector[r].first;
    if(sum == targetSum) {
        res.push_back(pairVector[l].second);
        res.push_back(pairVector[r].second);
        return ;
    }
    
    int mid = (l + r) / 2;

    if(sum < targetSum) {
        bSearch(l + 1, r);
    } else {
        bSearch(l, r - 1);
    }
 }
    vector<int> twoSum(vector<int>& nums, int target) {
        targetSum = target;
        for(int i = 0; i < nums.size(); ++i) {
            pairVector.push_back({nums[i], i});
        }
        sort(pairVector.begin(), pairVector.end());
        bSearch(0, nums.size() - 1);
        
        return res;
    }
    
};