class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int i = 0; int j = 1;
        int mmax = -1;
        bool alpha[300] = {false};
        while(i < s.size() && j < s.size()) {
            alpha[s[i]] = true; // b
            if(alpha[s[j]] == true && i < j) {
                alpha[s[i]] = false;
                i++;
        
            } else {
                alpha[s[j]] = true;
                j++;
                mmax = max(mmax,j - i);
            }

        }
        
        return mmax;
    }
};