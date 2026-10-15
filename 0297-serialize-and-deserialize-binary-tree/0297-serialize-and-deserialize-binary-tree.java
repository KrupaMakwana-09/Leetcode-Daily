public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>(); //allowes nulls
        q.offer(root);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            if (curr == null) {
                sb.append("n,");
                continue;
            }
            sb.append(curr.val).append(',');
            q.offer(curr.left);
            q.offer(curr.right);
        }

        return sb.deleteCharAt(sb.length() - 1).toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] tokens = data.split(",");
        Map<Integer, TreeNode> map = new HashMap<>();
        int index = 0;
        int nonNull = 1;

        for (int i = 0; i < tokens.length; i++) {
            if (tokens[i].equals("n")) {
                index++;
                continue;
            }
            int currValue = Integer.parseInt(tokens[i]);
            TreeNode newNode = new TreeNode(currValue);
            map.put(nonNull, newNode);
            //root node no parent
            if (nonNull != 1) {
                int parentIndex = (int)Math.ceil((double)index/2);
                TreeNode parentNode = map.get(parentIndex);

                //oddIndex = leftNode
                if (index % 2 == 1) {
                    parentNode.left = newNode;
                //evenIndex = rightNode
                } else {
                    parentNode.right = newNode;
                }
            }
            index++;
            nonNull++;
        }

        return map.get(1);
    }
}

