class Solution {
public:
    int visited[50050];
    void bfs (vector<int>& arr, int start) {
        queue<int> que;
        que.push(start);
        while(!que.empty()) {
            int top = que.front();
            que.pop();
            
            if(visited[top]) {
                continue;
            }
            visited[top] = true;
            
            if(top - arr[top] >= 0) que.push(top - arr[top]);
            if(top + arr[top] < arr.size()) que.push(top + arr[top]);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        bfs(arr, start);
        for(int i = 0 ; i < arr.size(); ++i) {
            if(arr[i] == 0 && visited[i]) return true;
        }
        return false;
    }
};