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
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        
        if(root.left == null && root.right == null)  return true;
        
        Stack<TreeNode> st = new Stack<>();
        st.push(root.left);
        st.push(root.right);
        
        while(!st.isEmpty()){
            TreeNode first = st.pop();
            TreeNode second = st.pop();
            if(first == null && second == null) continue;
            if(first == null || second == null) return false;
            if(first.val != second.val) return false;
            
            st.push(first.left);
            st.push(second.right);
            st.push(first.right);
            st.push(second.left);
        }
        return true;
    }
}