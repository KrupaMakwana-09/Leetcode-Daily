//C++ Code
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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> vec;
        while(head){
            vec.push_back(head);
            head = head->next;
        }
        sort(vec.begin(), vec.end(), [&](ListNode* a, ListNode* b){
            return a->val > b->val;
        });
        
        ListNode* prev = nullptr;
        for(int i = 0; i < vec.size(); i++){
            head = vec[i];
            head->next = prev;
            prev = head;
        }
        return head;
    }
};