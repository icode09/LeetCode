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
    vector<int> ans;
    void find(TreeNode* root){
        if(!root) return ;
        
       find(root->left);
       if(!root->left && !root->right) ans.push_back(root->val);
       find(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 && root2) return false;
        if(!root2 && root1) return false;
        find(root1);
        vector<int> leafValues1 = ans;
        ans.clear();
        
        find(root2);
        vector<int> leafValues2 = ans;
       
        
        if(leafValues1.size() != leafValues2.size()) return false;
        
        for(int i = 0;i<leafValues1.size();i++)
            if(leafValues1[i] != leafValues2[i]) return false;
        
        return true;
    }
};