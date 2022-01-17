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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        stack<pair<TreeNode*,int>> st;
        st.push({root,root->val});
        
        
        while(!st.empty()){
            TreeNode* top = st.top().first;
            int currSum = st.top().second;
            st.pop();
            
            
            if(!top->left && !top->right){
                if(currSum == targetSum)
                    return true;
            }
            
            if(top->right) st.push({top->right , currSum + top->right->val});
            if(top->left) st.push({top->left , currSum + top->left->val});
        }
        
        return false;
    }
};