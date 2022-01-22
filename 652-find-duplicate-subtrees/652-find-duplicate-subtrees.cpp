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
    string serialize(TreeNode* root,unordered_map<string,vector<TreeNode*>>& mapka){
     if(!root) return "";
        
     string key = "(" + serialize(root->left,mapka) + to_string(root->val) + serialize(root->right,mapka) + ")";
        
        mapka[key].push_back(root);
        
        return key;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> mapka;
        
        serialize(root,mapka);
        
        vector<TreeNode*> ans;
        
        for(auto it : mapka){
            vector<TreeNode*> temp = it.second;
            if(temp.size() > 1){
                ans.push_back(temp[0]);
            }
        }
        
        return ans;
    }
};