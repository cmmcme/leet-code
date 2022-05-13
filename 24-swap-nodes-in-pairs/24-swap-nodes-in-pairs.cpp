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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* first = new ListNode(0, head);    
        ListNode* prev = first;
        while(head != NULL && head->next != NULL) {
            ListNode* temp = head->next;
            head->next = temp->next;
            temp->next = head;
            
            prev->next = temp;
            prev = prev->next->next;
            head = head->next;
        }
        return first->next;
    }
};