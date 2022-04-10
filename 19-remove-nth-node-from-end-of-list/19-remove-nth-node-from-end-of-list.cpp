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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* first = head;
        while(first != nullptr) {
            first = first->next;
            size++;
        }
        if(size == n) return head->next;
        first = head;
        for(int i = 0; i < size - n - 1; ++i) first = first->next;
        first->next = first->next->next;
        
        return head;
    }
};