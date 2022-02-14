/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void toString(TreeNode* root,string& res){
        if(!root){
            res.push_back('#');
            res.push_back(' ');
            return;
        }
        
        res.append(to_string(root->val));
        res.push_back(' ');
        toString(root->left,res);
        toString(root->right,res);
    }
    string serialize(TreeNode* root) {
        string res;
        toString(root,res);
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string node;
        for(int i = 0;i<data.length();i++){
            if(data[i] == ' '){
                q.push(node);
                node.clear();
            }else{
                node.push_back(data[i]);
            }
        }
        
        return toTree(q);
    }
    TreeNode* toTree(queue<string>& q){
        if(q.front() == "#"){
            q.pop();
            return NULL;
        }
        int nodeVal = stoi(q.front());
        q.pop();
        
        TreeNode* root = new TreeNode(nodeVal);
        root->left = toTree(q);
        root->right = toTree(q);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));