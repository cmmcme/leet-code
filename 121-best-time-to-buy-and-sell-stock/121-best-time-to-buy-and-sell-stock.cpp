class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mmin = 987654321;
        int res = 0;
        for(int i = 0; i < prices.size(); ++i) {
            res = max(prices[i] - mmin, res);
            mmin = min(prices[i], mmin);
        }
        return res;
    }
};