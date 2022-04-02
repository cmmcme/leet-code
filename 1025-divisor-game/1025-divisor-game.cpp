class Solution {
public:
    int dp[1010];
    
    int func(int num) {
        if(num == 1) return dp[num] = 0;
        
        if(dp[num] != -1) return dp[num];
        
        for(int i = 1; i*i < num; ++i) {
            if(num % i != 0) continue;
            
            if(func(num - i) == 0) return dp[num] = 1; 
            if(i != 1 && func(num - (num/i) == 0)) return dp[num] = 1;
        }
        
        return dp[num] = 0;
    }
    bool divisorGame(int n) {
        memset(dp, -1, sizeof(dp));
        return func(n);
    }
};