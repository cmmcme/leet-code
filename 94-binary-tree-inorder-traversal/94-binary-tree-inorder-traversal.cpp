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
    
    void inorder(TreeNode* node) {
        if(node == NULL) return ;
        
        inorder(node->left);
        res.push_back(node->val);
        inorder(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        while(1) {
            while(root) {
                st.push(root);
                root = root -> left;
            }
            
            if(st.empty()) break;
            
            TreeNode* topNode = st.top();
            st.pop();
            res.push_back(topNode->val);
            root = topNode->right;
        }
        
        return res;
    }
};