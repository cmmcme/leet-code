class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
	vector<vector<bool>>visited;
	visited.resize(grid.size());
	for (int i = 0; i < visited.size(); i++)
		visited[i].resize(grid[0].size());
	    queue<pair<int, int>> que;
        auto isRange = [&grid](int y,int x) -> bool {
            if(y >= grid.size() || y<0 || x<0 || x >= grid[0].size())
                return false;
            return true;
        };
        
        auto bfs = [&grid, &que, &visited, &isRange]() -> bool {
		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { 1,0,-1,0 };
		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
            
            que.pop();
			for (int i = 0; i < 4; i++) {
				int nexty = y + dy[i];
				int nextx = x + dx[i];
				if(!isRange(nexty,nextx))
					continue;
				if (grid[nexty][nextx] == '1' && visited[nexty][nextx] == false) {
					que.push(make_pair(nexty, nextx));
					visited[nexty][nextx] = true;
				}
			}
		}
            return true;
	};
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size(); j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    que.push(make_pair(i,j));
                    bfs();
                    cnt++;
                }
            }
        }
        return cnt;
    }
};