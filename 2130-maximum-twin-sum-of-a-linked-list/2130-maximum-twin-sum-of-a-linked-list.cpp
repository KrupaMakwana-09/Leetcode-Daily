class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compute maximum twin sum
        int maxTwinSum = 0;

        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            maxTwinSum = max(maxTwinSum,
                             firstHalf->val + secondHalf->val);

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxTwinSum;
    }
};