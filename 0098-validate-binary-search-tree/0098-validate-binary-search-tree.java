/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        /**
        with recursion
        doing inorder traversal and checking if it's strictly increasing order or not
         */
        List<Integer> list = new ArrayList<>();
        //inOrder(root, list);
        
        for(int i = 0; i < list.size() - 1; i++){
            if(list.get(i) >= list.get(i + 1))
                return false;
        }

        return check(root, (long)(Integer.MIN_VALUE) - 1, (long)(Integer.MAX_VALUE) + 1);
    }
    static void inOrder(TreeNode node, List<Integer> list){
        if(node == null)    return;
        if(node.left != null)   inOrder(node.left, list);
        list.add(node.val);
        if(node.right != null)  inOrder(node.right, list);
    }
    static boolean check(TreeNode node, long min, long max){
        if(node.val >= max || node.val <= min)
            return false;

        boolean left = node.left != null? check(node.left, min, (long)node.val) : true;
        boolean right = node.right != null? check(node.right, (long)node.val, max) : true;

        return left && right;
    }
}