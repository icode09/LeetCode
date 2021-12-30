class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front();q.pop();
                
                if(word == endWord) return steps;
                
                dict.erase(word);
                for(int i = 0;i<word.size();i++){
                    char ch = word[i];
                    for(int j = 0 ; j< 26;j++){
                        word[i] = 'a' + j;
                        if(dict.find(word) != dict.end()){
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            steps++;
        }
        
        return 0;
    }
};