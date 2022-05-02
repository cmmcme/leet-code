class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> graph;
    graph.resize(numCourses + 1);
    vector<int> inNodesEdgeSize;
    inNodesEdgeSize.resize(numCourses + 1);
    
    for(int i = 0; i < prerequisites.size(); ++i) {
        int start = prerequisites[i][0];
        int end = prerequisites[i][1];
        graph[start].push_back(end);
        inNodesEdgeSize[end]++;
    }
    
    queue<int> que;
    for(int i = 0; i < numCourses; ++i) {
        if(inNodesEdgeSize[i] == 0) que.push(i);
    }
    vector<bool> visited;
    visited.resize(numCourses + 1);
    fill(visited.begin(), visited.begin() + numCourses + 1, false);
    
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        visited[node] = true;
        
        for(int i = 0; i < graph[node].size(); ++i) {
            int end = graph[node][i];
            if(visited[end] == false) {
                inNodesEdgeSize[end]--;
            }
            
            if(inNodesEdgeSize[end] == 0) que.push(end);
        }
    }
    
    for(int i = 0; i < numCourses; ++i) {
        if(visited[i] == false) return false;
    }
    
    return true;
    }
};