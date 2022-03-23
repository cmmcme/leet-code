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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* beforeNode = new ListNode(-200); 
        ListNode* ret = beforeNode;   
        // 이전 노드를 강제로 만들어줌. -200은 나올 수 없는 수   
        
        while(head != NULL) {
            if(head->val != beforeNode->val) {
                beforeNode->next = new ListNode(head->val);
                beforeNode = beforeNode->next;
            }
            head = head->next;
        }
        
        return ret->next;
    }
};