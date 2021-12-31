class TrieNode{
 public:
    vector<TrieNode*> children;
    string isWord;
    TrieNode(){
        this->children = vector<TrieNode*>(26,NULL);
        this->isWord = "";
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;
        for(int i = 0;i<board.size();i++){
            for(int j = 0 ;j<board[0].size();j++){
                dfs(board,i,j,ans,root);
            }
        }
        
        return ans;
    }
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(auto word : words){
          TrieNode* curr = root;
            for(int i = 0;i<word.size();i++){
            int index = word[i] - 'a';
            if(!curr->children[index])
                curr->children[index] = new TrieNode();
            
            curr = curr->children[index];
        }
        curr->isWord = word;
        }
        return root;
    }
     
    
    void dfs(vector<vector<char>>& board,int i,int j, vector<string>& ans,TrieNode* root){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') return ;
        
        char ch = board[i][j];
        if(!root->children[ch - 'a']) return ;
        
        root = root->children[ch - 'a'];
        if(root->isWord != ""){
            ans.push_back(root->isWord);
            root->isWord = "";
        }
        
        board[i][j] = '#';
        dfs(board,i+1,j,ans,root);
        dfs(board,i-1,j,ans,root);
        dfs(board,i,j+1,ans,root);
        dfs(board,i,j-1,ans,root);
        
        board[i][j] = ch;
    }
};