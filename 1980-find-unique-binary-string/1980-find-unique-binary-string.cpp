class Solution {
public:
    int length;
    set<string> numSet;
    pair<bool, string> dfs(int idx, string res) {
        if(idx == length) {
            if(numSet.count(res) == 0) {
                return make_pair(true, res);
            } 
            return make_pair(false, "");
        }
         pair<bool, string> ret = dfs(idx + 1, res + "1");
        if(ret.first == true) return ret;
        
  //      if(res.compare("0")) return make_pair(false, "");
        ret = dfs(idx + 1, res + "0");
        if(ret.first == true) return ret;

        
        return make_pair(false, "");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for (string x : nums) {
            numSet.insert(x);
        }
        length = nums.size();
        pair<bool, string> res = dfs(0, "");
        return res.second;
    }
};