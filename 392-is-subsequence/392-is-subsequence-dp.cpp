class Solution {
public:
    int dp[10010][110];
    bool isSubSeq(int tIdx, string t, int sIdx, string s)
    {
        if(tIdx >= t.size() && sIdx < s.size() - 1) return false;
    
        
        if(sIdx == s.size()) return true;
    
        
        if(tIdx >= t.size()) return false;
    
        
        if(dp[tIdx][sIdx] != -1) return dp[tIdx][sIdx];
        
        if(t[tIdx] == s[sIdx]) {
            return dp[tIdx][sIdx] = isSubSeq(tIdx + 1, t, sIdx + 1, s);
        } else {
            return dp[tIdx][sIdx] =  isSubSeq(tIdx + 1, t, sIdx, s);
        }
    }
    
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;
        
        for(int i = 0; i < t.size(); ++i) {
            if(t[i] != s[0]) continue;
            
            if(isSubSeq(i, t, 0, s)) return true;
        }
        
        return false;
    }
};
