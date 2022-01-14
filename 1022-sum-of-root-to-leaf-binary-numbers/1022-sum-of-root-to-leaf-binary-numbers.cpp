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
    int ans = 0;
    void dfs(TreeNode* root,int sum){
        if(!root) return ;
        
        sum  = (sum << 1) | root->val;
        
        if(!root->left && !root->right) ans += sum;
        
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        
        int sum = 0;
        
        dfs(root,sum);
        
        return ans;
    }
};