class Solution {
public:
    struct TrieNode{
      vector<TrieNode*> children;
        string word;
        bool isEnd;
        
        TrieNode(){
            this->word = "";
            this->isEnd = false;
            this->children = vector<TrieNode*>(26,NULL);
        }
    };
    
    
    void insert(TrieNode* root,string& word){
        TrieNode* curr = root;
        for(int i = 0;i<(int)word.size();i++){
            int idx = word[i] - 'a';
            if(!curr->children[idx])
                curr->children[idx] = new TrieNode();
            
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->word = word;
    }
    string findLongestWord(TrieNode* root){
        string res = "";
        queue<TrieNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TrieNode* front = q.front();
                q.pop();
                for(int i = 25;i>=0;i--){
                    if(front->children[i] && front->children[i]->isEnd){
                        res = front->children[i]->word;
                        q.push(front->children[i]);
                    }
                }
            }
        }
        return res;
    }
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
         
        for(auto w : words){
            insert(root,w);
        }
        
        return findLongestWord(root);
    }
};