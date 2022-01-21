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
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        
        stack<TreeNode*> st;
        int minDiff = INT_MAX;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* top = st.top();
            st.pop();
            
            if(prev){
                minDiff = min(minDiff , top->val - prev->val);
            }
            
            prev = top;
            curr = top->right;
        }
        
        return minDiff;
    }
};