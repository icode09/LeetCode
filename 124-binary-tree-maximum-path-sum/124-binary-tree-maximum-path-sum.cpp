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
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int max_single = max(max(left,right) + root->val , root->val);
        int max_top = max(max_single, left + right + root->val);
        
        ans = max(max_top , ans);
        
        return max_single;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        
        return ans;
    }
};