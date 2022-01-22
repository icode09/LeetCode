/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* nextRight(Node* root){
        Node* curr = root->next;
        while(curr){
            if(curr->left) return curr->left;
            else if(curr->right) return curr->right;
            
            curr = curr->next;
        }
        
        return NULL;
    }
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        Node* curr = root;
        curr->next = NULL;
        
        while(curr){
            Node* levelNode = curr;
            while(levelNode){
                if(levelNode->left){
                    if(levelNode->right) levelNode->left->next = levelNode->right;
                    else levelNode->next = nextRight(levelNode);
                }
                if(levelNode->right)
                    levelNode->right->next = nextRight(levelNode);
                
                levelNode = levelNode->next;
            }
            if(curr->left) curr = curr->left;
            else if(curr->right) curr = curr->right;
            else curr = nextRight(curr);
        }
        
        return root;
    }
};