/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        // MORRIS PREORDER TRAVERSAL
        vector<int> ans;

        TreeNode* curNode = root;

        while(curNode) {

            // No left Child => process node, go right
            if(!curNode->left) {
                ans.push_back(curNode->val);
                curNode = curNode->right;
                continue;
            }

            TreeNode* pred = curNode->left;
            
            // find predecessor => right most node of left child
            // go to right until there is no right child (nullptr)
            // or the right child is the thread (curNode)
            while(pred->right && pred->right != curNode) {
                pred = pred->right;
            }

            
            // first visit => process node, create thread to return to parent later, go left            
            if(!pred->right) {
                ans.push_back(curNode->val);
                pred->right = curNode;
                curNode = curNode->left;
            } else {
                // coming from to left subtree => destory threaad, go right
                pred->right = nullptr;
                curNode = curNode->right;
            }
        }

        return ans;
    }
};