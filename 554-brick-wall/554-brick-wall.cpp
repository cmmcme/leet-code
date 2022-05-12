class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> posToGapSize;
        for(int i = 0; i < wall.size(); ++i) {
            int nowPos = 0;
            for(int j = 0; j < wall[i].size() - 1; ++j) {
                nowPos += wall[i][j];
                if(posToGapSize.find(nowPos) == posToGapSize.end()) {
                    posToGapSize[nowPos] = 1;
                } else {
                    posToGapSize[nowPos] += 1;
                }
            }
        }
        int mmax = 0;
        for(auto it = posToGapSize.begin(); it != posToGapSize.end(); ++it) {
            mmax = max(mmax, it->second);
        }
        
        return wall.size() - mmax;
    }
};