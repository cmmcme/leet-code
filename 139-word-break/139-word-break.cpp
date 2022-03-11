class Solution {
public:
bool dp[303] = {false};

    bool wordBreak(string s, vector<string>& wordDict) {
    set<string> workSet(wordDict.begin(), wordDict.end());

    for(int i = 0; i < s.size(); ++i) {
        for(int j = i; j >= 0; --j) {
            if(j-1 < 0 || dp[j-1] == true) {
                string substr = s.substr(j, i - j + 1);
                if(workSet.count(substr)) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    
    return dp[s.size() - 1];
    }
};