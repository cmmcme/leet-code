class Solution {
public:
    int parent[1010];
    int parents(int n) {
        if(parent[n] == n) return n;
        
        return parent[n] = parents(parent[n]);
    }
    bool unionFind(int a, int b) {
        int a1Parent = parents(parent[a]);
        int b1Parent = parents(parent[b]);
        

        if(a1Parent == b1Parent) return true;
        
        parent[b1Parent] = parent[a1Parent];
        
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 1; i <= edges.size(); ++i) {
            parent[i] = i;
        }
        vector<int> res;
        for(int i = 0; i < edges.size(); ++i) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            
            if(unionFind(node1, node2)) {
                res = edges[i];
            }
        }
        return res;
    }
};