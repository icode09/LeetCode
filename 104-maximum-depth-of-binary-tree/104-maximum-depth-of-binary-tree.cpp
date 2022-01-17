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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        
        int maxLevel = 1;
        
        while(!st.empty()){
            TreeNode* top = st.top().first;
            int level = st.top().second;
            st.pop();
            
            if(maxLevel < level){
                maxLevel = level;
            }
            
            if(top->right) st.push({top->right , level + 1});
            if(top->left) st.push({top->left , level + 1});
        }
        
        return maxLevel;
    }
};