class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        int dp[3] = {2, 3, 5};
        for(int i = 0; i < 3; ++i) {
            while(n % dp[i] == 0) {
                n = n / dp[i];
            }
        }
        return n == 1;
    }
};