class Solution {
public:
     vector<string> res;
    void permutate(int open, int close, int n, string s) {
        if(open == n && close == n) {
            res.push_back(s);
            return ;
        }
        
        if(open < n) {
            permutate(open + 1, close, n, s + "(");
        }
        
        if(open <= n, close < open) {
            permutate(open, close + 1, n, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        permutate(0, 0, n, "");
        return res;
    }
};