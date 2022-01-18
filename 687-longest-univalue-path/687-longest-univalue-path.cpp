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
    int ans;
    int dfs(TreeNode* node){
        int l = node->left ? dfs(node->left) : 0;
        int r = node->right ? dfs(node->right) : 0;
        
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        
        ans = max(ans, resl + resr);
        return max(resl, resr);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        
        dfs(root);
        
        return ans;
    }
};