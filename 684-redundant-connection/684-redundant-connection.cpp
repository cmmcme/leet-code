class Solution {
public:
    int parents[1010];
    bool isUnionEdges[1010] = {false};
    int getParent(int son) {
        if(parents[son] == son) return son;
        return parents[son] = getParent(parents[son]);
    }
    
    void unionParent(int first, int second) {
        int firstParent = getParent(first);
        int secondParent = getParent(second);
        
        if(first < second) parents[secondParent] = firstParent;
        else parents[firstParent] = secondParent;
    }
    
    bool isSameParent(int first, int second) {
        int firstParent = getParent(first);
        int secondParent = getParent(second);
        
        return firstParent == secondParent;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        for(int i = 1; i <= edges.size(); ++i) {
            parents[i] = i;
        }
        
        for(int i = 0; i < edges.size(); ++i) {
            int first = edges[i][0];
            int second = edges[i][1];
            if(isSameParent(first, second)) continue;
            isUnionEdges[i] = true;
            unionParent(first, second);
        }
        
        for(int i = edges.size() - 1; i >= 0; --i) {
            if(!isUnionEdges[i]) return edges[i];
        }
        
        return res;
    }
};