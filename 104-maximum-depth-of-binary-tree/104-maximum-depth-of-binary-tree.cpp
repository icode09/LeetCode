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
    int maxLevel;
    void dfs(TreeNode* root,int currLevel){
        if(!root) return ;
        
        if(maxLevel < currLevel){
            maxLevel = currLevel;
        }
        
        dfs(root->left,currLevel+1);
        dfs(root->right,currLevel + 1);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        maxLevel = 1;
        int currLevel = 1;
        dfs(root,currLevel);
        
        return maxLevel;
    }
};