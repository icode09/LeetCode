class Solution {
public:
    struct Trie{
      bool isLeaf;
      unordered_map<char,Trie*> children;
        
      Trie(){
          isLeaf = false;
      }
    };
    void insert(Trie* head,string& str){
        Trie* curr = head;
        
        for(auto ch :str){
            if(curr->children.find(ch) == curr->children.end()){
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }
        curr->isLeaf = true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        Trie* head = new Trie();
        for(string s : strs){
            insert(head,s);
        }
        
        string lcp = "";
        
        Trie* curr = head;
        while(curr && curr->children.size() == 1 && !curr->isLeaf){
            auto it = curr->children.begin();
            
            lcp += it->first;
            
            curr = it->second;
        }
        
        return lcp;
    }
};