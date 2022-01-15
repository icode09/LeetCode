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
    unordered_map<int,TreeNode*> mapka;
    int findMaxIndex(vector<int>& nums,int start,int end){
        
        int index = start;
        int maxVal = nums[start];
        for(int i = start;i<=end;i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                index = i;
            }
        }
        
        return index;
    }
    TreeNode* maximumTree(vector<int>& nums,int start,int end){
        if(start > end ) return NULL;
        
        int index = findMaxIndex(nums,start,end);
        
        if(mapka.find(nums[index]) != mapka.end()) return mapka[nums[index]];
        
        TreeNode* root =  new TreeNode(nums[index]);
        
        root->left = maximumTree(nums,start,index - 1);
        root->right = maximumTree(nums,index + 1,end);
        
        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;
        if(n == 1) return new TreeNode(nums[0]);
        
        mapka.clear();
        
        return maximumTree(nums,0,n-1);
    }
};