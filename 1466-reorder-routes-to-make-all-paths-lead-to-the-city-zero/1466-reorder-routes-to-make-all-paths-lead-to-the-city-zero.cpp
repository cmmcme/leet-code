class Solution {
public:
bool visited[50010] = {false};
vector<vector<int>>vec;
int cnt = 0;
void dfs(int pos) {
    
    visited[pos] = true;
    
    for(int i = 0; i < vec[pos].size(); ++i) {
        int absConntectedNode = abs(vec[pos][i]);
        
        if(visited[absConntectedNode] == true) continue;
        
        if(vec[pos][i] < 0) cnt++;
        dfs(absConntectedNode);
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
    vec.resize(n);
    queue<int>que;
    que.push(0);
    for(int i = 0; i < connections.size(); ++i) {
        vec[connections[i][0]].push_back(connections[i][1]);
        vec[connections[i][1]].push_back(-connections[i][0]);
    }
    
    dfs(0);
    return n-1-cnt;
}
};