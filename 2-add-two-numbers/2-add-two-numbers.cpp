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
        while(reverseL1 != NULL || reverseL2 != NULL) {
            if(reverseL1 == NULL) {
                int sum = reverseL2->val + carry;
                carry = sum / 10;
                ListNode* list = new ListNode(sum % 10);
                current->next = list;
                current = list;
                reverseL2 = reverseL2->next;
                continue;
            }
            
            if(reverseL2 == NULL) {
                int sum = reverseL1->val + carry;
                carry = sum / 10;
                ListNode* list = new ListNode(sum % 10);
                current->next = list;
                current = list;
                reverseL1 = reverseL1->next;
                continue;
            }
            
            int sum = reverseL1->val + reverseL2->val + carry;
            carry = sum / 10;
            ListNode* list = new ListNode(sum % 10);
            current->next = list;
            current = list;
            reverseL1 = reverseL1->next;
            reverseL2 = reverseL2->next;
        }
        
        if(carry != 0) {
            ListNode* list = new ListNode(carry);
            current->next = list;
        }
        return test->next;
    }
};