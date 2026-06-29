// C++ implementation
class Solution {
public:
    int index = 0;
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            map[inorder[i]] = i;
        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->left = helper(preorder, start, mid - 1);
        root->right = helper(preorder, mid + 1, end);
        return root;
    }
};