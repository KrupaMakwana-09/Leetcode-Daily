class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        temp->next = head;
        k %= n;
        int newHead = n - k + 1;
        int newTail = n - k;
        ListNode* nh = head;
        ListNode* nt = head;

        for(int i = 1 ; i < newTail ; i++){
            nt = nt->next;
        }
        nh = nt->next;
        nt->next = nullptr;
        return nh;
    }
};