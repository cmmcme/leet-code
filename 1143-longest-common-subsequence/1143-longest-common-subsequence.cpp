class Solution {
public:
    
    int dp[1010][1010];
    
    int func(string text1, string text2, int text1Index, int text2Index) {
        if(text1Index >= text1.size() || text2Index >= text2.size()) {
            return 0;
        }
        if(dp[text1Index][text2Index] != -1) return dp[text1Index][text2Index];
        
        dp[text1Index][text2Index] = 0;
        
        if(text1[text1Index] == text2[text2Index]) {
            dp[text1Index][text2Index] += func(text1, text2, text1Index + 1, text2Index + 1) +  1;
        } else {
            dp[text1Index][text2Index] += max(func(text1, text2, text1Index + 1, text2Index), func(text1, text2, text1Index, text2Index + 1));
        }
        
        return dp[text1Index][text2Index];
    }
    int longestCommonSubsequence(string text1, string text2) {
        for(int i = text1.size() - 1; i >= 0; --i) {
            for(int j = text2.size() - 1; j >=0; --j) {
                if(text1[i] == text2[j]) {
                    dp[i][j] += dp[i + 1][j + 1] +  1;
                } else {
                    dp[i][j] += max(dp[i][j + 1], dp[i + 1][j]);                                                                     ;
                }
            }
        }
        return dp[0][0];
     //   return func(text1, text2, 0, 0);
    }
};