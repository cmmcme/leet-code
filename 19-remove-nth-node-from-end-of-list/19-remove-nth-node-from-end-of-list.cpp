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
    vector<ListNode*> arr;
    
    ListNode* front = head;
    int cnt = 0;
    
    while(front != NULL) {
        arr.push_back(front);
        front = front->next;
    }
  //  cout<<arr.size()<<' '<<arr.size() - n + 1<<' '<<arr.size() - n - 1<<endl;
        
    if(arr.size() == 1 && n == 1) return NULL;
    if(arr.size() == 2 && n == 1) return new ListNode(head->val);
    if(arr.size() == 2 && n == 2) return head->next;
    if(n == 1) {
        arr[arr.size() - 2]->next = NULL;
        return arr[0];
    }
    if(n == arr.size()) return arr[1];
    
    ListNode* prev = arr[arr.size() - n - 1];
    ListNode* after = arr[arr.size() - n + 1];
    cout<<prev->val<<' '<<after->val<<endl;
    prev->next = after;
    
    return arr[0];
    }
};