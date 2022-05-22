/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *list1 = headA;
        ListNode *list2 = headB;
        int aCount = 0;
        while(list1 != NULL) {
            aCount++;
            list1 = list1->next;
        }
        int bCount = 0;
        while(list2 != NULL) {
            bCount++;
            list2 = list2->next;
        }
        list1 = headA;
        list2 = headB; 
        if(aCount > bCount) {
            int count = aCount - bCount;
            while(count--) {
                list1 = list1->next;
            }
        } else if(aCount < bCount) {
            int count = bCount - aCount;
            while(count--) {
                list2 = list2->next;
            }
        } else {
            // do nothing
        }
        
        while(list1 != NULL && list2 != NULL) {
            if(list1 == list2) return list1;
            list1 = list1->next;
            list2 = list2->next;
        }
        
        return NULL;
    }
};