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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* lastNode = head;
        ListNode* middleNode = head;
        while(lastNode != NULL && lastNode->next != NULL) {
            lastNode = lastNode->next->next;
            middleNode = middleNode->next;
        }
        ListNode* prev = NULL;
        while(middleNode != NULL) {
            ListNode* temp = middleNode->next;
            middleNode->next = prev;
            prev = middleNode;
            middleNode = temp;
        }
        
        ListNode* left = head;
        ListNode* right = prev;
        
        while(right != NULL) {
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};