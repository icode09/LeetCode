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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stack;
        for(auto num : nums){
            TreeNode* curr = new TreeNode(num);
            while(!stack.empty() && stack.back()->val < curr->val){
                curr->left = stack.back();
                stack.pop_back();
            }
            if(!stack.empty()){
                stack.back()->right = curr;
            }
            stack.push_back(curr);
        }
        return stack.front();
    }
};