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
bool dfs(TreeNode* current, TreeNode* minNode, TreeNode* maxNode) {
    if(current == NULL) {
        return true;
    }
    
    if(minNode && current->val <= minNode ->val) return false;
    
    if(maxNode && current->val >= maxNode -> val) return false;
    
    return dfs(current->left, minNode, current) && dfs(current->right, current, maxNode);
}

bool isValidBST(TreeNode* root) {
    return dfs(root, NULL, NULL);
}
};