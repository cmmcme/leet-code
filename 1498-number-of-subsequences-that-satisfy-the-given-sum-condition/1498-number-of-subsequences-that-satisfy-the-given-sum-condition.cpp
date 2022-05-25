class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int l = 0;
        int r = nums.size() - 1;
        int mod = 1000000007;
        long long por[nums.size()+1];
        por[0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            por[i] = (2 * por[i-1]) % mod;
        }
        
        while(l <= r) {
            int lValue = nums[l];
            int rValue = nums[r];
            
            if(lValue + rValue > target) {
                r--;
            } else {
                count = ((count + por[r-l]) % 1000000007);
                l = l + 1;
            }
            
        }
        return count % mod;
    }
};