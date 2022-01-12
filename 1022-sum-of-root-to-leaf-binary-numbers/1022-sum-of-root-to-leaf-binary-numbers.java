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
    int ans;
    public int sumRootToLeaf(TreeNode root) {
        if(root == null) return 0;
        
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode root,int val){
        if(root == null) return ;
        
        val = (val << 1) | root.val;
        
        if(root.left == null && root.right == null){
            ans += val;
        }
        dfs(root.left,val);
        dfs(root.right,val);
    }
}