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
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        Node* curr = root;
        while(curr){
            Node* levelNode = curr;
            while(levelNode){
                if(levelNode->left){
                    levelNode->left->next = levelNode->right;
                    if(levelNode->next)
                        levelNode->right->next = levelNode->next->left;
                }
                levelNode = levelNode->next;
            }
            curr = curr->left;
        }
        
        return root;
    }
};