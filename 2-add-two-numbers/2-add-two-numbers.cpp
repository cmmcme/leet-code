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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reverseL1 = l1;
        ListNode* reverseL2 = l2;
        ListNode* test = new ListNode(0);
        ListNode* current = test;
        int carry = 0;
        int sum = 0;
        while(reverseL1 != NULL || reverseL2 != NULL) {
            if(reverseL1 == NULL) {
                sum = reverseL2->val + carry;
                reverseL2 = reverseL2->next;
            } else if(reverseL2 == NULL) {
                sum = reverseL1->val + carry;
                reverseL1 = reverseL1->next;
            } else {
                sum = reverseL1->val + reverseL2->val + carry;
                reverseL1 = reverseL1->next;
                reverseL2 = reverseL2->next;
            }
            carry = sum / 10;
            ListNode* list = new ListNode(sum % 10);
            current->next = list;
            current = list;
        }
        
        if(carry != 0) {
            ListNode* list = new ListNode(carry);
            current->next = list;
        }
        return test->next;
    }
};