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
    TreeNode* findInorderSucc(TreeNode* root, int key){
        TreeNode* curr = root->right;
        while(curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            // 3 Conditions => 1. No child, 2. Single child, 3. both childs
            if(!root->left && !root->right) return NULL;
            else if(!root->left){
                TreeNode* nextNode = root->right;
                delete root;
                return nextNode;
            }else if(!root->right){
                TreeNode* nextNode = root->left;
                delete root;
                return nextNode;
            }else{
                TreeNode* nextNode = findInorderSucc(root,key);
                root->val = nextNode->val;
                root->right = deleteNode(root->right,nextNode->val);
            }
        }
        return root;
    }
};