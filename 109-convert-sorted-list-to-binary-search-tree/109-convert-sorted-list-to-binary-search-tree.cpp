/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> vec;
    TreeNode* binarySearch(int l, int r) {
        if(l > r) return NULL;
        int mid = (l + r) / 2;
        int midValue = vec[mid];
        TreeNode* now = new TreeNode(midValue);
        now->left = binarySearch(l, mid - 1);
        now->right = binarySearch(mid + 1, r);
        return now;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        while(head != NULL) {
            vec.push_back(head->val);
            head = head -> next;
        }        
        return binarySearch(0, vec.size() - 1);
    }
};