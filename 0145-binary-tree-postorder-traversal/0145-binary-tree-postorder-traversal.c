/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int    total_nodes(struct TreeNode* root)
{
    if (!root)
        return (0);
    return ((total_nodes(root->left) + total_nodes(root->right)) + 1);
}

int*    loops(struct TreeNode* root, int* total, int *i)
{
    if (!root)
        return (NULL);
    loops(root->left, total, i);
    loops(root->right, total, i);
    total[*i] = root->val;
    (*i)++;
    return (total);
}

int*    postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *total;
    int nodes;
    int i;

    i = 0;
    *returnSize = total_nodes(root);
    total = malloc((*returnSize) * sizeof(int));
    if (!total)
        return (NULL);
    return (loops(root, total, &i));
}