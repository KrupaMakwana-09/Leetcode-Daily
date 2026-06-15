class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
   
        ListNode *slowPtr = head, *fastPtr = head->next->next;
     
        while (fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
       
        slowPtr->next = slowPtr->next->next;
        
        return head;
    }
};