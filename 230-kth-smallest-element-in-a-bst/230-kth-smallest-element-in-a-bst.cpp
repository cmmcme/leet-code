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
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        stack<TreeNode*> stack;
        TreeNode* now = root;
        while(1) {
            while(now != NULL) {
                stack.push(now);
                now = now -> left;
            }
            
            if(stack.empty()) break;
            
            now = stack.top();
            stack.pop();
            n++;
            if(n == k) return now->val;
            
            now = now->right;
        }
        
        return -1;
    }
};