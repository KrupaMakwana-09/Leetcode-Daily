class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int left = max(0, maxGain(node->left));
        int right = max(0, maxGain(node->right));

        maxSum = max(maxSum, node->val + left + right);

        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};