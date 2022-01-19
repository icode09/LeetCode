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
    int postindex;
    TreeNode* constructTree(vector<int>& postorder,int start,int end){
        if(postindex < 0 || start > end) return NULL;
        TreeNode* node = new TreeNode(postorder[postindex--]);
        if(start == end) return node;
        int index = mapka[node->val];
        
        node->right = constructTree(postorder,index + 1,end);
        node->left = constructTree(postorder,start,index - 1);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        int n = inorder.size();
        mapka.clear();
        postindex = postorder.size() - 1;
        for(int i = 0;i<postorder.size();i++){
            mapka[inorder[i]] = i;
        }
        
        return constructTree(postorder,0,n-1);
    }
};