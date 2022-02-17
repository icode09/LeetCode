class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin() , wordList.end());
        queue<string> to_visit;
        to_visit.push(beginWord);
        int ladder = 1;
        
        while(!to_visit.empty()){
            int size = to_visit.size();
            while(size--){
                string word = to_visit.front();
                to_visit.pop();
                
                if(word == endWord) return ladder;
                
                wordDict.erase(word); // marking it as already visited
                
                for(int i = 0;i<(int)word.size();i++){
                    char letter = word[i];
                    for(int j = 0;j<26;j++){
                        word[i] = (char)(j + 'a');
                        if(wordDict.find(word) != wordDict.end()){
                            to_visit.push(word);
                        }
                    }
                    word[i] = letter;
                }
            }
            ladder++;
        }
        
        return 0;
    }
};