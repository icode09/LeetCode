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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int nodes_in_this_level = size;
            long long sum = 0;
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                
                sum += front->val;
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            double val = (double)sum/(double)nodes_in_this_level;
            ans.push_back(val);
        }
        return ans;
    }
};