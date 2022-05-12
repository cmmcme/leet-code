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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head->next == NULL && head->val == val) return NULL;
        
        ListNode* now = head->next;
        ListNode* prev = head;
        while(now != NULL) {
            if(now->val == val) {
                prev->next = now->next;
                now = now->next;
            } else {
                prev = now;
                now = now->next;
            }
        }
        
        if(head->val == val) return head->next;
        return head;
    }
};