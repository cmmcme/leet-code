class Solution {
public:
    int lenght[2020];
    int cost[2020];
    int findNumberOfLIS(vector<int>& nums) {
        int mmaxLength = -1;
        for(int i = 0; i < nums.size(); ++i) {
            cost[i] = 1;
            lenght[i] = 1;
            
            for(int j = 0; j < i; ++j) {
                if(nums[i] <= nums[j]) continue;
                
                if(lenght[j] + 1 > lenght[i]) {
                    lenght[i] = lenght[j] + 1;
                    cost[i] = cost[j];
                } else if(lenght[j] + 1 == lenght[i]) {
                    cost[i] += cost[j];
                }
            }
            mmaxLength = max(mmaxLength, lenght[i]);
        }
        int res = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(mmaxLength == lenght[i]) res += cost[i];
        }
        return res;
    }
};
