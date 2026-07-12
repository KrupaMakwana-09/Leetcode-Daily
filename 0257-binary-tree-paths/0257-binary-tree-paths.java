
class Solution {
    static StringBuilder temp = new StringBuilder();

    static void printme(TreeNode root, ArrayList<String> list) {
        if (root == null) {
            return;
        }

        int length=temp.length();
        temp.append(String.valueOf(root.val + "->"));

        if (root.left == null && root.right == null) {
            list.add(temp.substring(0, temp.length() - 2));
            temp.setLength(length);
            return;
        }
        printme(root.left, list);
        printme(root.right, list);
        temp.setLength(length);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        ArrayList<String> list = new ArrayList<>();
        if (root.left == null && root.right == null) {
            list.add(String.valueOf(root.val));
            return list;
        }
        printme(root, list);
        return list;
    }
}