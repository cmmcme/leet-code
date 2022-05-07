/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> oldToNewMap;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0) return new Node(node->val);
        
        queue<Node*> oldQueue;
        oldQueue.push(node);
        oldToNewMap[node] =  new Node(node->val);
        
        while(!oldQueue.empty()) {
            Node* currentOldNode = oldQueue.front();
            oldQueue.pop();
            Node* currentNewNode = oldToNewMap[currentOldNode];
            for(int i = 0; i < currentOldNode->neighbors.size(); ++i) {
                Node* currentNeighbor = currentOldNode->neighbors[i];
                
                if(oldToNewMap.find(currentNeighbor) == oldToNewMap.end()) { // can't find!
                    oldQueue.push(currentNeighbor);
                    oldToNewMap[currentNeighbor] = new Node(currentNeighbor->val);
                }
                
                currentNewNode->neighbors.push_back(oldToNewMap[currentNeighbor]);
            }
        }
        
        return oldToNewMap[node];
    }
};