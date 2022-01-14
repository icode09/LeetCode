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
    void push(TreeNode* root,stack<TreeNode*>& st){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        stack<TreeNode*> st;
        
        push(root,st);
        
        while(!st.empty()){
            TreeNode* leftMost = st.top();
            st.pop();
            
            ans.push_back(leftMost->val);
            
            push(leftMost->right,st);
        }
        
        return ans;
    }
};