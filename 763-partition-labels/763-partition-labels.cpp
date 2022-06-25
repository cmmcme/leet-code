class Solution {
public:
    int alpha[30] = {-1};
    vector<int> partitionLabels(string s) {
        
        for(int i = 0; i < s.size(); ++i) {
            alpha[s[i] - 'a'] = i;
        }
        vector<int> res;
        int start = 0;
        int end = -1;
        for(int i = 0; i < s.size(); ++i) {
            end = max(alpha[s[i] - 'a'], end);
            if(end == i) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};