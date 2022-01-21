class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // length of maximum possible window
        
        int start = 0 , end = 0;
        int maxLen = 0;
        unordered_map<int,int> mapka;
        while(end < fruits.size()){
            mapka[fruits[end]]++;
            end++;
            while(mapka.size() > 2){
                mapka[fruits[start]]--;
                if(mapka[fruits[start]] == 0){
                    mapka.erase(fruits[start]);
                }
                start++;
            }
            
            maxLen = max(maxLen , end - start);
        }
        
        return maxLen;
    }
};