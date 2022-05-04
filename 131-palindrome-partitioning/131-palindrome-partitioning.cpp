class Solution {
public:
    vector<vector<string>> res;

bool isPallndrome(string s, int i, int j) {
    if(i >= j) return true;
    if(s[i] == s[j]) return isPallndrome(s, i + 1, j - 1);
    return false;
}
void func(int index, string s, vector<string> vec) {
    if(index >= s.length()) {
        res.push_back(vec);
        return;
    }
    
    for(int i = index; i < s.size(); ++i) {
        string subS = s.substr(index, i - index + 1);
        if(isPallndrome(subS, 0, subS.size() - 1)) {
            vec.push_back(subS);
            func(i + 1, s, vec);
            vec.pop_back();
        }
    }
}
    
    vector<vector<string>> partition(string s) {
            vector<string> vec;
    func(0, s, vec);
        
        return res;
    }
};