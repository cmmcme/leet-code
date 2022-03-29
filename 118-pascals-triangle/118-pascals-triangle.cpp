class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> vec;
    for(int i = 1; i <= numRows; ++i) {
        vector<int> rows;
        for(int j = 0; j < i; ++j) {
            if(j == i - 1 || j == 0) {
                rows.push_back(1);
            } else {
                int res = vec[i-2][j-1] + vec[i-2][j];
                rows.push_back(res);
            }
        }
        vec.push_back(rows);
    }
        return vec;
    }
};