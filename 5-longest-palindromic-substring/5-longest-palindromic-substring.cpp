class Solution {
public:
    int resSize = 0;
    int resL = 0;
    int resR = 0;
    void func(int l, int r, string s) {
        while(r < s.size() && l >= 0 && s[l] == s[r]) {
            if(r - l + 1 > resSize) {
                resL = l;
                resR = r;
                resSize = r - l + 1;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        for(int i = 0; i < s.size(); ++i) {
            func(i, i, s);
            func(i, i + 1, s);
        }
        
        string res = "";
        for(int i = resL; i <= resR; ++i) res += s[i];
        
        return res;
    }
};