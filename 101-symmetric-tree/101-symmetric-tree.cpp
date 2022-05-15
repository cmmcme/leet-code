/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// BFS 로 풀면 될 듯 합니다
class Solution {
public:
    bool BFS(TreeNode* now) {
        queue<TreeNode*> que;
        que.push(now);
        
        while(!que.empty()) {
            vector<int> comp;
            int queSize = que.size();
            
            for(int i = 0; i < queSize; ++i) {
                TreeNode* front = que.front();
                que.pop();
                if(front == NULL) {
                    comp.push_back(200);
                    continue;
                }
                
                que.push(front->left);
                que.push(front->right);
                comp.push_back(front->val);
            }
            
            for(int i = 0; i < comp.size() / 2; ++i) {
                if(comp[i] != comp[(comp.size() - 1) - i]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return BFS(root);
    }
};