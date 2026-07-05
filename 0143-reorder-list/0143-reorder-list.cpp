class Solution {
private:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* mid = middleNode(head);

        ListNode* second = mid->next;
        mid->next = NULL;

        ListNode* first = head;
        second = reverseList(second);

        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;

        while (first && second) {
            temp1 = first->next;
            temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;

            if (first)
                second = temp2;
        }

        if (temp2) {
            second->next = temp2;
        }
    }
};