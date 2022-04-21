class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int mmax = 0;
        for(int i = 0; i < s.size(); i++) {
            bool z[300] = {false};
            z[s[i]] = true;
            int cnt = 1;
            for(int j = i + 1; j < s.size(); j++) {
                if(z[s[j]] == true) {
                    break; 
                }
                else { 
                    z[s[j]] = true;
                    cnt ++;
                }
            }
            mmax = max(mmax, cnt);
        }
        
        return mmax;
    }
};