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
        if(head == NULL) return head;
        
        ListNode* now = head -> next;
        ListNode* prev = head;
        while(now != NULL) {
            if(now->val != val) {
                prev = now;
                now = now->next;
                continue;
            }
            prev->next = now->next;
            now = now->next;
        }
        return head->val == val? head->next : head;
    }
};