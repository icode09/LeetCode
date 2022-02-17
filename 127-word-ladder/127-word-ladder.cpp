class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin() , wordList.end());
        queue<string> to_visit;
        addWord(to_visit,wordDict,beginWord);
        int dist = 2;
        
        while(!to_visit.empty()){
            int size = to_visit.size();
            while(size--){
                string word = to_visit.front();
                to_visit.pop();
                
                if(word == endWord) return dist;
                addWord(to_visit,wordDict,word);
            }
            dist++;
        }
        
        return 0;
    }
    void addWord(queue<string>& to_visit,unordered_set<string>& wordDict, string& word){
        for(int i = 0;i<(int)word.length();i++){
            char letter = word[i];
            for(int j = 0;j<26;j++){
                word[i] = (char)(j + 'a');
                if(wordDict.find(word) != wordDict.end()){
                    to_visit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};