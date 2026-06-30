class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(size(q)) {
            Node* rightNode = nullptr;                    
            for(int i = size(q); i; i--) {                
                auto cur = q.front(); q.pop();            
                cur -> next = rightNode;                  
                rightNode = cur;                          
                if(cur -> right)                         
                    q.push(cur -> right),                
                    q.push(cur -> left);                  
            }
        }
        return root;
    }
};