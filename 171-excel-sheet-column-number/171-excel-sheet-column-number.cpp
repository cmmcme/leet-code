class Solution {
public:
    const int ALPHA_SIZE = 26;
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(int i = 0; i < columnTitle.size(); ++i) {
            res = (ALPHA_SIZE) * res + (columnTitle[i] - 'A' + 1);
        }
        return res;
    }
};