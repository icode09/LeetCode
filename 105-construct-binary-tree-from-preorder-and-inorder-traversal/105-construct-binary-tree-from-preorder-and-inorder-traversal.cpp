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
    unordered_map<int,int> mapka;
    TreeNode* dfs(vector<int>& preorder,int& startPreorder,int startInorder,int endInorder){
        if(startPreorder >= preorder.size() || startInorder > endInorder) return NULL;
        
        TreeNode* root = new TreeNode(preorder[startPreorder]);
        int index = mapka[preorder[startPreorder]];
        startPreorder++;
        
        root->left = dfs(preorder,startPreorder,startInorder,index-1);
        root->right = dfs(preorder,startPreorder,index+1,endInorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mapka.clear();
        for(int i = 0;i<inorder.size();i++){
            mapka[inorder[i]] = i;
        }
        int startPreorder = 0;
        return dfs(preorder,startPreorder,0,inorder.size() - 1);
    }
};