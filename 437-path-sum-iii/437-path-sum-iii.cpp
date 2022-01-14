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
    void dfs(TreeNode* root, int targetSum,int sum,unordered_map<int,int>& mapka,int& count){
        if(!root) return ;
        
        sum += root->val;
        
        if(sum == targetSum) count++;
        
        if(mapka.find(sum - targetSum) != mapka.end()) count += mapka[sum - targetSum];
        
        mapka[sum]++;
        
        dfs(root->left,targetSum,sum,mapka,count);
        dfs(root->right,targetSum,sum,mapka,count);
        
        mapka[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> mapka;
        
        int count = 0;
        
        dfs(root,targetSum,0,mapka,count);
        
        return count;
    }
};