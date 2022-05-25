class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, bool> rowMap;
        map<int, bool> colMap;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == 0) {
                    colMap[i]  = true;
                    rowMap[j] = true;
                }
            }
        }
        
        for(auto it = rowMap.begin(); it != rowMap.end(); ++it) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][it->first] = 0;
            }
        }
        
        for(auto it = colMap.begin(); it != colMap.end(); ++it) {
            int n = it->first;
            for(int i = 0; i < matrix[n].size(); ++i) {
                matrix[n][i] = 0;
            }
        }
    }
};