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
    bool isEqual(TreeNode* root, int val){
        if(!root) return true;
        if(root->val != val) return false;
        
        return isEqual(root->left,val) && isEqual(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int data = root->val;
        
        return isEqual(root->left,data) && isEqual(root->right,data);
    }
};