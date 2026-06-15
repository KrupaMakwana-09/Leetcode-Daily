// Helper function to find the k-th node from a given starting pointer
struct ListNode* getKthNode(struct ListNode* curr, int k) {
    while (curr && k > 0) {
        curr = curr->next;
        k--;
    }
    return curr;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }
    
    // Create a dummy node on the stack to simplify head changes
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* group_prev = &dummy;
    
    while (1) {
        // 1. Locate the k-th node of the current group
        struct ListNode* kth = getKthNode(group_prev, k);
        if (!kth) {
            break; // Fewer than k nodes left; keep remaining as-is
        }
        
        struct ListNode* group_next = kth->next;
        
        // 2. Reverse the nodes within the current group
        struct ListNode* prev = group_next;
        struct ListNode* curr = group_prev->next;
        
        while (curr != group_next) {
            struct ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        // 3. Connect the surrounding boundaries
        struct ListNode* tmp = group_prev->next; // The original head of the group is now the tail
        group_prev->next = kth;                 // Connect previous group to the new head
        group_prev = tmp;                       // Move group_prev forward for the next loop
    }
    
    return dummy.next;
}
