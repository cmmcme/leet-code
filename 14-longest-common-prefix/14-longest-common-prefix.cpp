class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        int shorestLength = 202;
        for(int i = 0; i < strs.size(); ++i) {
            shorestLength = shorestLength > strs[i].size() ? strs[i].size(): shorestLength;
        }
        
        string res;
        while(index < shorestLength) {
            char ch = strs[0][index];
            bool isSame = true;
        for(int i = 1; i < strs.size(); ++i) {
            if(ch != strs[i][index]) {
                isSame = false;
                break;
            }
        }
        if(!isSame) {
            return strs[0].substr(0, index);
        }
        index++;
        }
        return strs[0].substr(0, shorestLength);
    }
};