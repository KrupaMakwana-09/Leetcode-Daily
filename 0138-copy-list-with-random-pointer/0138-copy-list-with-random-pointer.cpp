/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // **First Pass: Interweave original and copied nodes**
        Node* temp = head;
        while (temp) {
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }

        // **Second Pass: Assign random pointers**
        temp = head;
        while (temp) {
            Node* node = temp->next; // The copy
            // The copy's random pointer points to the next of the original's random pointer
            if (temp->random) {
                node->random = temp->random->next;
            } else {
                node->random = nullptr;
            }
            temp = node->next; // Move to the next original node
        }

        // **Third Pass: Separate the two lists**
        Node* newHead = head->next;
        temp = head;
        while (temp) {
            Node* node = temp->next;
            // Restore original list's next pointer
            temp->next = node->next; 
            
            // Set copied list's next pointer
            if (node->next) {
                node->next = node->next->next;
            }
            
            // Move to the next original node
            temp = temp->next;
        }
        
        return newHead;
    }
};