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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        
        if(checkSimilar(root,subRoot)) return true;
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool checkSimilar(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(root && !subRoot) return false;
        if(!root && subRoot) return false;
        
        if(root->val != subRoot->val) return false;
        
        return checkSimilar(root->left,subRoot->left) && checkSimilar(root->right,subRoot->right);
    }
};