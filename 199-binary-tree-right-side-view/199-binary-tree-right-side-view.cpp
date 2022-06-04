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
class Solution {
public:
    vector<int> res;
    void bfs(TreeNode* current) {
        queue<TreeNode*> que;
        
        que.push(current);
        while(!que.empty()) {
            int queSize = que.size();
            
            for(int i = 0; i < queSize; ++i) {
                TreeNode* top = que.front();
                que.pop();
                if(top == NULL) continue;
                
                if(i == queSize - 1) {
                    res.push_back(top->val);
                }
                
                if(top->left != NULL) que.push(top->left);
                if(top->right != NULL) que.push(top->right);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return res;
    }
};