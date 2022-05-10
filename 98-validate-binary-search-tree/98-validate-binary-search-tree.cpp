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
bool dfs(TreeNode* current, TreeNode* left, TreeNode* right) {
    if(current == NULL) {
        return true;
    }
    
    if(left && current->val <= left ->val) return false;
    
    if(right && current->val >= right -> val) return false;
    
    return dfs(current->left, left, current) && dfs(current->right, current, right);
}

bool isValidBST(TreeNode* root) {
    return dfs(root, NULL, NULL);
}
};