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
    TreeNode* findInorderSucc(TreeNode* root){
        TreeNode* curr = root->right;
        while(curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteThisNode(TreeNode* root){
        if(!root) return NULL;
        
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        else{
            TreeNode* nextNode = findInorderSucc(root);
            nextNode->left = root->left;
            return root->right;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        TreeNode* curr = root, *prev = NULL;
        while(curr && curr->val != key){
            prev = curr;
            if(curr->val < key){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        
        if(!prev) return deleteThisNode(root);
        
        if(prev->left == curr){
            prev->left = deleteThisNode(curr);
        }
        else {
            prev->right = deleteThisNode(curr);
        }
        
        return root;
    }
};