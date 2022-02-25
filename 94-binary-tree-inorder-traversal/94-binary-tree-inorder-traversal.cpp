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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        stack<TreeNode*> st;
        
        TreeNode* curr = root;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* leftMost = st.top();
            st.pop();
            
            ans.push_back(leftMost->val);
            
            if(leftMost->right) curr = leftMost->right;
        }
        
        return ans;
    }
};