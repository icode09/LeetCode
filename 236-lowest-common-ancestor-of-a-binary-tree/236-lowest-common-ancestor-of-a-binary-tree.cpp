/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        
        unordered_map<TreeNode* , TreeNode*> parent;
        stack<TreeNode*> st;
        st.push(root);
        parent.insert({root,nullptr});
        
        // Assumption is that the Tree contains both nodes p and q
        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()){
            TreeNode* curr = st.top();
            st.pop();
            
            if(curr->left){
                parent[curr->left] = curr;
                st.push(curr->left);
            }
            
            if(curr->right){
                parent[curr->right]  = curr;
                st.push(curr->right);
            }
        }
        
        // From p we try to move up, and store the path in set
        unordered_set<TreeNode*> res;
        while(p){
            res.insert(p);
            p = parent[p];
        }
        
        while(res.find(q) == res.end())
            q = parent[q];
        
        return q;
    }
};