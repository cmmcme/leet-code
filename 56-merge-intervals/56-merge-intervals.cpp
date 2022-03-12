class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    map<int, int> mp;
    for(int i = 0; i < intervals.size(); i++) {
        mp[intervals[i][0]] ++;
        mp[intervals[i][1]] --;

    }
    int fistValue = -1;
    int sum = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(sum == 0) fistValue = it->first;
        sum += it->second;
        
        if(sum == 0) {
            vector<int> vec4;
            vec4.push_back(fistValue);
            vec4.push_back(it->first);
            res.push_back(vec4);

        }
    }
        return res;
    }
};