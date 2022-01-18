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
    int dfs(TreeNode* root,int& ans){
        if(!root) return 0;
        
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        
        int resL = (root->left && root->left->val == root->val) ? left + 1 : 0;
        int resR = (root->right && root->right->val == root->val) ? right + 1 : 0;
        
        ans = max(ans , resL + resR);
        
        return max(resL, resR);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        
        int ans = 0;
        
        dfs(root,ans);
        
        return ans;
    }
};