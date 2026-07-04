class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode a = headA;

        while (a != null) {
            ListNode b = headB;

            while (b != null) {
                if (a == b)
                    return a;

                b = b.next;
            }

            a = a.next;
        }

        return null;
    }
}